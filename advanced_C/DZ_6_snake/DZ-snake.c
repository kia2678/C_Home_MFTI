#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
double DELAY = 0.1;
uint8_t PLAYERS  = 2;
#define RED 1
#define BLUE 2
#define GREEN 3

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=30, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=3,CONTROLS=2};

uint8_t color_list[3] = {0};
uint8_t control_ai_list[2] = {0};

// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls[CONTROLS] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
                                                    {'s', 'w', 'a', 'd'}};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    uint8_t color;
    uint8_t control_ai;
    uint8_t activity;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;
/*
 Еда — это массив точек, состоящий из координат x,y, времени,
 когда данная точка была установлена, и поля, сигнализирующего,
 была ли данная точка съедена.
 */
struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

//================ инициализация еды ===================================
void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
//========================================================================

//==================== функция назначения цвета =========================
void setColor(int objectType)
{
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    switch (objectType)
    {
        case 1:{ // SNAKE1
            attron(COLOR_PAIR(1));
            break;
        }
        case 2:{ // SNAKE2
            attron(COLOR_PAIR(2));
            break;
        }
        case 3:{ // FOOD
            attron(COLOR_PAIR(3));
            break;
        }
    }
}
//========================================================================

 //========== Обновить/разместить текущее зерно на поле ===============
void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    setColor(color_list[2]);
    mvprintw(fp->y, fp->x, "%s", spoint);
}
//========================================================================

//================== Разместить еду на поле =============================
void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}
//========================================================================

//================== инициализация хвоста змейки =========================
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t= {0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
//========================================================================

//=================== инициализация голвы змейки =========================
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}
//========================================================================

//========================= инициализация змейки =========================
void initSnake(snake_t *head[], uint8_t color[], uint8_t a_i[], size_t size, int x, int y,int i)
{
    head[i]    = (snake_t*)malloc(sizeof(snake_t));
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->color = color[i];
    head[i]->control_ai = a_i[i];
    head[i]->tail     = tail; // прикрепляем к голове хвост
    head[i]->tsize    = size+1;
    head[i]->controls = default_controls[i];
    head[i]->activity = 1;
}
//========================================================================

//====== Движение головы с учетом текущего направления движения =========
void go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    setColor(head->color);
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
        case LEFT:
        if(head->x <= 0) // Циклическое движение, чтобы не уходить за пределы экрана
            head->x = max_x;
        mvprintw(head->y, --(head->x), "%c", ch);
    break;
    case RIGHT:
        if(head->x >= max_x) // Циклическое движение, чтобы не уходить за пределы экрана
            head->x = 0;
        mvprintw(head->y, ++(head->x), "%c", ch);
    break;
    case UP:
        if(head->y <= 0) // Циклическое движение, чтобы не уходить за пределы экрана
            head->y = max_y;
        mvprintw(--(head->y), head->x, "%c", ch);
    break;
    case DOWN:
        if(head->y >= max_y) // Циклическое движение, чтобы не уходить за пределы экрана
            head->y = 0;
        mvprintw(++(head->y), head->x, "%c", ch);
    break;
    default:
    break;
    }
    refresh();
}
//========================================================================

// ========== опрос кнопок и установка направления движения =============
void changeDirection(struct snake_t* snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}
//========================================================================

//============ Движение хвоста с учетом движения головы ================
void goTail(struct snake_t *head)
{
    char ch = '*';
    setColor(head->color);
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}
//========================================================================

//=========Проверка того, является ли какое-то из зерен съеденным =======
_Bool haveEat(struct snake_t *head, struct food f[])
{
    for(int i = 0; i < SEED_NUMBER; i++)
    {
        if(head->x == f[i].x && head->y == f[i].y)
        {
            f[i].enable = 0;
            return 1;
        }
    }
    return 0;
}
//========================================================================

//=============Увеличение хвоста на 1 элемент =============================
void addTail(struct snake_t *head)
{
    head->tsize++;
}
//========================================================================

//========================================================================
int checkDirection(snake_t* snake, int32_t key)
{
    if(snake->direction != UP && (key == snake->controls.down))
        return 1;
    else if (snake->direction != DOWN && (key == snake->controls.up))
        return 1;
    else if (snake->direction != LEFT && (key == snake->controls.right))
        return 1;
    else if (snake->direction != RIGHT && (key == snake->controls.left))
            return 1;
    return 0;

}

//Вынести тело цикла while из int main() в отдельную функцию update
//и посмотреть, как изменится профилирование
void update(struct snake_t *head, struct food f[], const int32_t key)
{
    clock_t begin = clock();
    if (head->control_ai)
        autoChangeDirection(head, f, SEED_NUMBER);
    go(head);
    goTail(head);
    if (checkDirection(head, key))
    {
        changeDirection(head, key);
    }
    refreshFood(food, SEED_NUMBER); // Обновляем еду
    if (haveEat(head, food))
    {
        addTail(head);
    }
    refresh(); // Обновление экрана, вывели кадр анимации

    while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY)
    {}
}
//========================================================================

//==========функция проверки на столкновения головы с хвостом ===========
_Bool isCrush(snake_t * snake)
{
    for(size_t i = snake->tsize-1; i>0; i--)
    {
        if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y)
        {
            return 1;
        }
    }
    return 0;
}
//========================================================================
//========= прооверка на размещение зерна ================================
void repairSeed(struct food f[], size_t nfood, struct snake_t *head)
{
    /* Если хвост совпадает с зерном */
    for( size_t i=0; i<head->tsize; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
            if(head->tail[i].x == f[j].x && head->tail[i].y == f[j].y)
            {
                putFoodSeed(&f[j]);
            }
        }
    /* Если два зерна на одной точке */
    for( size_t i=0; i<nfood; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
            if(!(i==j) && (f[i].x == f[j].x && f[i].y == f[j].y))
            putFoodSeed(&f[j]);
        }
}

//======Добавление ИИ========================================================
// вычисляет количество ходов до еды
int distance(const snake_t snake, const struct food food) {
    return (abs(snake.x - food.x) + abs(snake.y - food.y));
}
//Для автоизменения направления напишем функцию
//Она определяет ближайшую к себе еду и движется по направлению к ней
void autoChangeDirection(snake_t *snake, struct food food[], int foodSize)
{
    int pointer = 0;
    for (int i = 1; i < foodSize; i++) {   // ищем ближайшую еду
        pointer = (distance(*snake, food[i]) < distance(*snake, food[pointer])) ? i : pointer;
    }
    if ((snake->direction == RIGHT || snake->direction == LEFT) &&
        (snake->y != food[pointer].y)) {  // горизонтальное движение
        snake->direction = (food[pointer].y > snake->y) ? DOWN : UP;
    } else if ((snake->direction == DOWN || snake->direction == UP) &&
               (snake->x != food[pointer].x)) {  // вертикальное движение
        snake->direction = (food[pointer].x > snake->x) ? RIGHT : LEFT;
    }
}
//========================================================================

//==========функция стартового меню===================================
void startMenu(uint8_t* players, uint8_t color[], uint8_t control[])
{
    char players_n = 0;
    char color_1 = 0;
    char color_2 = 0;
    char color_food = 0;
    char control_1 = 0;
    char control_2 = 0;
    setColor(GREEN);
    mvprintw(13, 10,"Welcome to the snake game");
    mvprintw(15, 10, "select the number of players (1 or 2)");
    while((players_n = getch()))
    {
        if(players_n == '1' || players_n == '2')
        {
            *players = players_n - '0';
            if(players_n == '1')
                DELAY *=2;
            break;
        }
    }
    mvprintw(15, 10, "snake control 1                       ");
    mvprintw(16, 10, "(1 - player, 2 - bot)");
    while((control_1 = getch()))
    {
        if(control_1 == '1' || control_1 == '2')
        {
            control[0] = control_1 - '0' - 1;
            break;
        }
    }
    if(players_n == '2')
    {
        mvprintw(15, 10, "snake control 2");
        mvprintw(16, 10, "(1 - player, 2 - bot)");
        while ((control_2 = getch()))
        {
            if (control_2 == '1' || control_2 == '2')
            {
                control[1] = control_2 - '0' - 1;
                break;
            }
        }
    }
    mvprintw(15, 10, "choice of color for snake 1");
    mvprintw(16, 10, "(1 - red, 2 - blue, 3 - green)");
    while((color_1 = getch()))
    {
        if(color_1 == '1' ||color_1 == '2' || color_1 == '3')
        {
            color[0] = color_1 - '0';
            break;
        }
    }
    if(players_n == '2')
    {
        mvprintw(15, 10, "choice of color for snake 2");
        mvprintw(16, 10, "(1 - red, 2 - blue, 3 - green)");
        while ((color_2 = getch()))
        {
            if (color_2 == '1' || color_2 == '2' || color_2 == '3')
            {
                color[1] = color_2 - '0';
                break;
            }
        }
    }
    mvprintw(15, 10, "choice of food color       ");
    mvprintw(16, 10, "(1 - red, 2 - blue, 3 - green)");
    while((color_food = getch()))
    {
        if(color_food == '1' || color_food == '2' || color_food =='3')
        {
            color[2] = color_food - '0';
            break;
        }
    }
    clear();
}
//========================================================================

//=========== Функция проверки окончания игры ============================
void end_status(snake_t *snake, uint8_t max_len_snake, int* end)
{
    if(snake->activity == 0)
        *end = *end - 1;
    if(snake->tsize >= max_len_snake)
        *end = 0;
}
//========================================================================

//======== Функция вывода из игры змейки при столкновении с хвостом ======
void snake_exit(snake_t *snake)
{
    snake->activity = 0;
    snake->x = 0;
    snake->y = 0;
}
//========================================================================

//========== Функция вывода набраных очков на экран ======================
void result_points(snake_t *snake, uint8_t color[], int n)
{
    if(n == 0)
    {
        setColor(color[n]);
        mvprintw(0, 5, "snake result (1) = %d", snake->tsize - 1 - START_TAIL_SIZE);
    }

    if(n == 1)
    {
        setColor(color[n]);
        mvprintw(0, 30, "snake result (2) = %d", snake->tsize - 1 - START_TAIL_SIZE);
    }
}
//========================================================================

// ============ Функция вывода статуса игроков в конце игры ==============
void status_end_game(snake_t** snekes, int max)
{
    if(PLAYERS == 1)
    {
        if(snekes[0]->tsize < max)
        {
            setColor(GREEN);
            mvprintw(13,40,"  ---SNAKE GAME OVER---  ");
        }
        else
        {
            setColor(RED);
            mvprintw(13,40,"  ---SNAKE VICTORI!!!---  ");
        }
    }
    if(PLAYERS == 2)
    {
        if(snekes[0]->tsize > snekes[1]->tsize)
        {
            setColor(GREEN);
            mvprintw(13,40,"  ---SNAKE (1) VICTORI!!!---  ");
            setColor(RED);
            mvprintw(14,40,"  ----SNAKE (2) GAME OVER---  ");
        }
        else if (snekes[0]->tsize < snekes[1]->tsize)
        {
            setColor(GREEN);
            mvprintw(13,40,"  ---SNAKE (2) VICTORI!!!---  ");
            setColor(RED);
            mvprintw(14,40,"  ----SNAKE (1) GAME OVER---  ");
        }
        else
        {
            setColor(GREEN);
            mvprintw(13,40,"  ---DEAD HEAT---  ");
        }
    }
    timeout(7000);
    getch();
}
//========================================================================


int main()
{
    initscr();

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    noecho();            // Отключаем echo() режим при вызове getch
    startMenu(&PLAYERS, color_list, control_ai_list);
    raw();                // Откдючаем line buffering
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    curs_set(FALSE);    //Отключаем курсор
    setColor(0);
    mvprintw(0, 55,"Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле

    snake_t* snakes[PLAYERS];
    for (int i = 0; i < PLAYERS; i++)
        initSnake(snakes, color_list, control_ai_list, START_TAIL_SIZE, 10+i*10,10+i*10,i);
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна

    int key_pressed=0;
    int end = PLAYERS;
    while( key_pressed != STOP_GAME  && end)
    {
        key_pressed = getch(); // Считываем клавишу
        for (int i = 0; i < PLAYERS && end > 0; i++)
        {
            if(snakes[i]->activity)
            {
                update(snakes[i], food, key_pressed);
                if (isCrush(snakes[i]))
                {
                    snake_exit(snakes[i]);
                    DELAY *=2;
                }
                end_status(snakes[i], MAX_TAIL_SIZE, &end);
                result_points(snakes[i], color_list, i);
                repairSeed(food, SEED_NUMBER, snakes[i]);
            }
        }
    }
    status_end_game(snakes, MAX_TAIL_SIZE);
    for (int i = 0; i < PLAYERS; i++)
    {
        //printExit(snakes[i]);
        free(snakes[i]->tail);
        free(snakes[i]);
    }
    endwin(); // Завершаем режим curses mod
    return 0;
}
