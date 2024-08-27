#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "temp_functions.h"


// считываем строку и записываем 6 целочисленных параметров в масив, также проверяем на ошибки формата данных строки
int reader(FILE*in, int data[])
{
    int res = 0;
    char str[22] = {0}; 
    char c;
    int i = 0;
    while ((c = fgetc(in)) != '\n' && c != '\0' && c != EOF && i < 22) // считываем строку и завписываем в str[22]
        str[i++] = c;

    if(str[i-1] == ' ')      // проверяем на пробел в конце строки и заменяем его на конец строки
        str[i-1] = '\0';
    else                     // иначе просто ставим конец строки
        str[i] = '\0'; 
    
    if(!(str[(strlen(str)) - 1] >= '0' && str[(strlen(str)) - 1] <= '9'))  // проверяем последниий символ строки на корректность
        return 0;
    return sscanf(str, "%d;%d;%d;%d;%d;%d;%d", &data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6]); // заносим целые числа в массив
}

// проверяем крректность данных
int err_or(int data[], int year)
{
    int res = 0;

    if(data[0] != year)
        res = 1;
    if(!(data[1] > 0 &&  data[1] <= 12))
        res = 1;
    if(!(data[2] > 0 &&  data[2] <= 31))
        res = 1;
    if(!(data[3] >= 0 &&  data[3] < 24))
        res = 1;
    if(!(data[4] >= 0 &&  data[4] < 60))
        res = 1;
    if(!(data[5] > -100 &&  data[5] < 100))
        res = 1;
        
    return res;
}

// заносим данные в массив структур
void save_m_struct(struct stt *term, int *data)
{
    if (term->counter == 0) // заносим начальные значения  максимальной и минимальной температуры
    {
        term->max_t = data[5];
        term->min_t = data[5];
    }
    if ((term + data[1])->counter == 0) // заносим начальные значения  максимальной и минимальной температуры для каждого месяца
    {
        (term + data[1])->max_t = data[5];
        (term + data[1])->min_t = data[5];
    }

    (term + data[1])->sum_aver_t += data[5]; // сумируем значение температуры
    term->sum_aver_t += data[5];

    (term + data[1])->counter++; // счетчик
    term->counter++;

    if(term->max_t < data[5])   // находим максимальную температуру
        term->max_t = data[5];
    if((term + data[1])->max_t < data[5])
        (term + data[1])->max_t = data[5];

    if (term->min_t > data[5]) // находим минимальную температуру
        term->min_t = data[5];
    if ((term + data[1])->min_t > data[5])
        (term + data[1])->min_t = data[5];
}


// вычисляем среднюю температуру
void calcul_aver_t(struct stt *term)
{
    for (int i = 0; i < 13; ++i)
    {
        if ((term + i)->counter)
            (term + i)->aver_t = (float)(term + i)->sum_aver_t / (term + i)->counter;
    }
}


// определяем год
int define_year(FILE *in)
{
    int year_1 = 0;
    int year_2 = 0;
    int cunter_1 = 0;
    int cunter_2 = 0;

    for (int i = 0; i < 5 && (!feof(in)); i++)
    {
        int a = 0;
        int s[7];

        a = reader(in, s); // считываем построчно данные с файла (должно быть 6 чисел)

        if (a == 6)
        {
            if (year_1 == 0)
                year_1 = s[0];

            if (s[0] != year_1)
            {
                if (year_2 == 0)
                    year_2 = s[0];
            }
                if (year_1 == s[0])
                    cunter_1++;
                if (year_2 == s[0])
                    cunter_2++;
        }
    }
    fseek(in, 0, SEEK_SET);  // переходим в начало файла
    return (cunter_1 > cunter_2) ? year_1 : year_2;
}

// Вывод информации по ключам (аргументам командной строки)

void print_argum(void)
{
    printf(
"The application displays statistics for one calendar year:\n"
"- average monthly temperature\n"
"- minimum temperature in the current month\n"
"- maximum temperature in the current month\n\n"
"Also statistics for the year:\n" 
"- average annual temperature\n" 
"- minimum temperature\n"
"- maximum temperature\n\n"
"The application processes command line arguments:\n" 
"set of supported keys:\n"
"  -h                  Description of the application functionality. List of keys that this application processes and their purpose.\n"
"  -f <filename.csv>   input csv file to process (separated by space!).\n"
"  -m <month number>   if this key is specified, then only statistics for the specified month are displayed (separated by space!).\n\n"
"**********************************************************************************************************************************\n\n");
}


// Миню ввода ключей и параметров
int menu_arg(char* name_file, int* month)
{
    printf(
    "To exit the program press   < q >\n"
    "To specify the processing of data from the desired file, press   < f >, path and file name (max. 100 characters)\n"
    "To display statistics for the selected month, press  <m>  and then enter a number from 1 to 12\n"
    "To continue the program press < g >\n\n"
    "****************************************************************************************************************************\n");
    while (1)
    {
        printf("\nplease enter the required key:  ");
        char s[100] = {0};
        char c = 0;
        scanf("%c", &c);             // считываем ключ

        switch (c)
        {
        case 'q':         // выход из прогаммы
                    return 1;
            break;
        case 'f':   printf("\nplease enter the file name:  ");   //назначаем файл для обработки
                    scanf("%s", name_file);
                    
                    printf("Selected file to process < %s >\n", name_file);
                    getchar(); // чтобы убрать с потока '\n'
            break;
        case 'm':   printf("\nplease enter the month number:  ");  // указываем месяц за который выводим статистику
                    scanf("%d", month);
                    if(!(*month > 0 && *month <= 12))
                    {
                        printf("you entered an incorrect value!\n");
                        *month = 0;    // если введенное значение не корректно, то сбрасываем на 0 
                    }
                    printf("< %d > month selected for displaying statistics\n", *month);
                    getchar();  // чтобы убрать с потока '\n'          
            break;
        case 'g':          // дальнешее выполнение программы
                    return 0;
            break;
        }
    }
    return 0;
}

// функция вывода статистики
void print_static (FILE* err_in, FILE* result, struct stt *term, int err_cunter, int month, int year)
{
    char c;
    if(err_cunter)
    {
        while ((c = fgetc(err_in)) != EOF)  
        putchar(c);
    }
    printf("\n**** display temperature statistics ****\n\n");

    if(month == 0)
    {
        printf("=========== for %d year =============\n", year);
        printf("average temperature for the year = %.2f\nminimum temperature for the year = %d\nmaximum temperature for the year = %d\n",
              term->aver_t, term->min_t, term->max_t);
        printf("=======================================\n\n");

        fprintf(result, "=========== for %d year =============\n", year);
        fprintf(result, "average temperature for the year = %.2f\nminimum temperature for the year = %d\nmaximum temperature for the year = %d\n",
               term->aver_t, term->min_t, term->max_t);
        fprintf(result, "=======================================\n\n");

        for(int i = 1; i < 13; ++i)
        {
            printf("------------- for %d month -------------\n", i);
            printf("average temperature per month = %.2f\nminimum temperature per month = %d\nmaximum temperature per month = %d\n",
                  (term + i)->aver_t, (term + i)->min_t, (term + i)->max_t);
            printf("---------------------------------------\n\n");

            fprintf(result, "------------- for %d month -------------\n", i);
            fprintf(result, "average temperature per month = %.2f\nminimum temperature per month = %d\nmaximum temperature per month = %d\n",
                   (term + i)->aver_t, (term + i)->min_t, (term + i)->max_t);
            fprintf(result, "---------------------------------------\n\n");
        }
    }
    else
    {
        printf("------------- for %d month -------------\n", month);
        printf("average temperature per month = %.2f\nminimum temperature per month = %d\nmaximum temperature per month = %d\n",
              (term + month)->aver_t, (term + month)->min_t, (term + month)->max_t);
        printf("---------------------------------------\n\n");

        fprintf(result, "------------- for %d month -------------\n", month);
        fprintf(result, "average temperature per month = %.2f\nminimum temperature per month = %d\nmaximum temperature per month = %d\n",
               (term + month)->aver_t, (term + month)->min_t, (term + month)->max_t);
        fprintf(result, "---------------------------------------\n");
    }
}