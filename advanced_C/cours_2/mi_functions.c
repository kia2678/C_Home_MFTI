#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "mi_functions.h"

//====== функция F1 = 0.6x + 3 =======
float f_1(float x)
{
    return 0.6 * x + 3;
}
//************************************


//=== функция F2 = (x − 2)**3 – 1 ====
float f_2(float x)
{
    return (pow((x-2), 3)) - 1;
}
//************************************


//======== функция F3 = 3/X ==========
float f_3(float x)
{
    return 3 / x;
}
//************************************


//== функция F0 = X-X (возвращает 0) ==
float f_0(float x)
{
    return x - x;
}
//************************************



//====================================================================================
//-------------------- ищет точку пересечения функций --------------------------------
//====================================================================================
//xl - левая граница диапазона; xr - правая граница диапазона; eps2 - заданная точность;
// f_a - указатель на функцию; f_b - указатель на функцию, с которой пересечется; 
// name - имя точки (символ 'a', 'b', 'c' ...)
root_f root_find(float xl, float xr, float eps, function f_a, function f_b, char name)
{
    root_f root = {};   //создаём структуру, значение которой будем возвращать
    root.name = name;   // присваеваем имя точки вычисленного пересечения функции(идентично имени струкруры)
    int count = 0;      // счетчик итераций
    float quarter = fabs(xr-xl) / 4; // четверть интервала вычисляемого диапазона функции
    
    while (fabs(xr-xl) > eps)  //пока интервал больше значения точности
    { 
        count++;       // увеличеваем счетчик итераций
        float l = f_a(xl + quarter) - f_b(xl + quarter);          // значение 1/4 значение  диапазона 
        float r = f_a(xl + quarter * 3) - f_b(xl + quarter * 3);  // значение 3/4 значение  диапазона 
        if(fabs(l) < fabs(r))       // если слева значение (от середины диапазона) меньше
        {
            xr = xl + quarter * 2;  // присваеваем новое значение правой границы (середина интервала)
            quarter = fabs(xr-xl) / 4; // находим новую четверть интервала
        }
        if(fabs(l) > fabs(r))      // если справа значение (от середины диапазона) меньше
        {
            xl = xl + quarter * 2;  // присваеваем новое значение левой границы (середина интервала)
            quarter = fabs(xr-xl) / 4;  // находим новую четверть интервала
        }
        if(fabs(l) == fabs(r) && l != r) // если значение по модулю равны, 
                          //а фактически отличаются знаком - изменить -xl-
            xl -= eps;    // отнимаем на значение точности от левой границы интервала
    }
    root.counter = count;      // заносим в структуру данные о количестве итераций
    root.x = xl + quarter * 2; // заносим в структуру данные по координате Х 
    root.y = f_a(root.x);      // заносим в структуру данные по координате Y
    return root;               // возвращаем вычисленные данные структуры
}
//************************************************************************************



//====================================================================================
//----------------- вычисляет интеграл функции ---------------------------------------
//====================================================================================
// xl - леввая граница диапазона; xr - правая граница диапазона
// eps2 - заданная точность; f_a - указатель на функцию
float integral(float xl, float xr, float eps2, function f_a)
{
    float interg = 0; // значение вычисленного интеграла
    for(float i = xl + eps2/2; i <= xr - eps2/2; i += eps2) // цикл по количеству прямоугольников высчитанный 
                                                            // на основании точности (от середины прямоугольника)
        interg += fabs(f_a(i)) * eps2; // суммируем площадь прямоугольников
    return interg;
}
//************************************************************************************



//====================================================================================
//---------- выводит справку по ключу -h с последующим переходом в меню --------------
//====================================================================================
// fl_1 - флаг (вывод данных по точкам); fl_2 - флаг (вывод количества итераций); 
// eps - точность расчета по точкам; eps2 - точность расчета интеграла
int menu_arg(int* fl_1, int* fl_2, float* eps, float* eps2)
{
    int flag = 0; // флаг для входа в меню
    int ffl = 1;  // флаг для входа в цикл (выбор дальнейшего действия после вывода справки на экран)
    printf("\n"
    " This program is designed to calculate the area of a figure\n"
    " limited by three curves described by the formulas:\n"
    " 1. F1 = 0.6x +3\n"
    " 2.F2 = (x-2)**3 - 1\n"
    " 3.F3 = 3/x\n\n"
    "********************************************************************************\n\n"
    "Command line arguments:\n"
    " -h  calls up help with further transition to the program menu.\n"
    " -a  displays the coordinates of the intersection of functions.\n"
    " -b displays the number of iterations to find intersection points.\n"
    " -f  sets the accuracy of determining intersection points (default 0.001).\n"
    " -i  sets the accuracy of integral calculations (default 0.001).\n\n"
    "********************************************************************************\n\n");
    printf(
        " To continue the program, press < g >\n"
        " To exit, press < q >\n"
        " To enter the menu, press < m >\n\n"
        " please enter the required key: ");
    while (ffl) //выбор дальнейшего действия после вывода справки на экран
    {
        char c = 0; // для занесения выбранной команды
        scanf("%c", &c);             

        switch (c)
        {
        case 'q':         // выход из прогаммы
                    return 1;
            break;
        case 'g':         // продолжение выполнения программы 
                    return 0;
            break;
        case 'm':         // вход в меню
                    flag = 1;
                    ffl = 0; 
            break;
        }
        getchar();  // чтобы убрать с потока '\n'
    }
    if(flag)
    {             //описание функционала меню
        printf( 
            "\n******************************* MENU *******************************************\n\n"
            " Select further actions by pressing keys from the list provided below.\n\n"
            " To exit the program press   < q >\n"
            " To display the coordinates of the intersection of functions, press < a >\n"
            " displays the number of iterations to find intersection points, press < b >\n"
            " To determine the accuracy of searching for intersection points of functions, press < f >\n"
            " To determine the accuracy of integral calculations, press < i >\n"
            " To continue the program press < g >\n\n"
            "********************************************************************************\n");
    }
    while (flag) // цикл меню
    {
        printf("\n please enter the required key: ");
        char c = 0;                  // для занесения выбранной команды
        scanf("%c", &c);             // считываем ключ

        switch (c)
        {
        case 'q':         // выход из прогаммы
                    return 1;
            break;
        case 'a':         // устанавливаем флаг для вывода данных по точкам на экран
                    printf("\n When executing the program, information with the coordinates of the points will now be displayed!\n");
                    *fl_1 = 1;
                    getchar();       
            break;
        case 'b':         // устанавливаем флаг для вывода количества итераций по вычислению точки
                    printf("\n Now information about the number of iterations to calculate the point will be displayed!\n");
                    *fl_2 = 1;
                    getchar();   
            break;
        case 'f':         // установка значения точности при вычислении точки
                    printf("\n Enter a number from 0.1 to 0.00001:  ");  
                    scanf("%f", &(*eps)); 
                    if(!(*eps >= 0.00001 && *eps <= 0.1))
                    {
                        printf(" you entered an incorrect value!\n");
                        *eps = 0.001;    // если введенное значение некорректно, то сбрасываем на 0.001 
                    }                  
                    getchar(); // чтобы убрать с потока '\n'
            break;
        case 'i':          // установка значения точности при вычислении интеграла
                    printf("\n Enter a number from 0.1 to 0.00001:  ");  
                    scanf("%f", &(*eps2));
                    if(!(*eps2 >= 0.00001 && *eps2 <= 0.1))
                    {
                        printf(" you entered an incorrect value!\n");
                        *eps2 = 0.001;    // если введенное значение некорректно, то сбрасываем на 0.001 
                    }
                    getchar();  // чтобы убрать с потока '\n'          
            break;
        case 'g':          // дальнешее выполнение программы
                    printf("\n********************************************************************************\n\n");
                    return 0;
            break;
        }
    }
    return 0;
}
//************************************************************************************


//====================================================================================
//------------------ вывод на экран данных по точкам ---------------------------------
//====================================================================================
// a, b, c, d, e, - структуры с данными по точка; flag_count - флаг для вывода количества итераций
void prin_t_root(root_f a, root_f b, root_f c, root_f d, root_f e, int flag_count)
{
    root_f fff[5] = {a, b, c, d, e};  // создаем массив из структур
    printf("\n********************************************************************************\n\n");
    printf(" Coordinates of the intersection points of the functions:\n\n");
    for(int i = 0; i < 5; i++)  // выводим информацию на экран для каждой точки (a, b, c, ...)
    {
        printf(" point \"%c\" has coordinates: X = %10.6f   Y = %10.6f   ", fff[i].name, fff[i].x, fff[i].y);
        if (flag_count)
            printf("calculated in --%3d -- iterations", fff[i].counter);
        printf("\n");
    }    
}
//************************************************************************************
