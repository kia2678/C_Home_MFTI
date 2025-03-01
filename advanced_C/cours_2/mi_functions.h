#ifndef FF_mi_FUNCTIONS
#define FF_mi_FUNCTIONS

typedef struct root_f  // структура где мы храним данные по точке пересечения функций
{
    char name;         // имя точки
    int counter;       // количество итераций для вычисления
    float x;           // данные координаты Х
    float y;           // данные координаты Y
}root_f;

typedef float(*function)(float); // тип указателя на функцию

float f_1(float x);  // возвращает значение функции F1
float f_2(float x);  // возвращает значение функции F2
float f_3(float x);  // возвращает значение функции F3
float f_0(float x);  // вспомогательная функция, возвращает 0

root_f root_find(float xl, float xr, float eps, function f_a, function f_b, char name); // ищет точку пересечения функций
float integral(float xl, float xr, float eps2, function f_a);   // вычисляет интеграл функции
int menu_arg(int* fl_1, int* fl_2, float* eps, float* eps2);   // выводит справку по ключу -h с последующим переходом в меню
void prin_t_root(root_f a, root_f b, root_f c, root_f d, root_f e, int flag_count); //вывод на экран данных по точкам

#endif