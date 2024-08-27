#include "temp_functions.h"


int main(int argc, char* argv[]) 
{
    struct stt term[13] = {}; // хранятся значения статистики по каждому месяцу и за весь год(ter[0])
    uint32_t n_str = 0;       // счетчик строк
    char name_file[101] = {0}; // название файла для считывния
    int month = 0;            // номер месяца для вывода статистики, если 0 то за весь год
    int err_cunter = 0;       // счетчик ошибок
                
    int argum = 0;
    while ((argum = getopt(argc, argv, "hf:m:")) != -1) // обработчик аргументов
    {
        switch (argum)
        {
        case 'h':       print_argum(); 
                        if(menu_arg(name_file,  &month))
                            return 0;    
                                                  break;

        case 'f':       sscanf(optarg, "%s", name_file);
                                                  break;

        case 'm':       sscanf(optarg, "%d", &month);
                                               break;
        }
    }

    if(strlen(name_file) == 0)   // если файл не задан то будет использоваться по умолчанию "temperature_small.csv"
            sprintf(name_file, "temperature_test.csv");
    
    in = fopen(name_file, "r");
    err = fopen("error.txt", "w");
    err_in = fopen("error.txt", "r");
    result = fopen("static.txt", "w");

    if(in == NULL)
    {
        printf("File <%s> not found! Run the temp_st.exe file with the <h> or <f> key\n");
        return 1;
    }
    fprintf(err, "File  %s\n", name_file);
    fprintf(result, "File  %s  Statistics\n\n", name_file);

    int year = define_year(in); // определяем какой год для последуещей проверки корректных данных

    while (!feof(in))
    {    
        int a = 0;             // сколько чисел было считано со строки (должно быть 6 чисел)
        int s[7];              // масив с числами считаных со строки (должно быть 6 чисел)
       
        a = reader(in, s);     // считываем построчно данные с файла (должно быть 6 чисел)
        if(err_or(s, year))    // проверяем корректность данных
            a = 0;

        if(a == 6)
        {
            save_m_struct(term, s); // заносим данные в массив из структур
            //printf("%d;%d;%d;%d;%d;%d\n" , s[0], s[1], s[2], s[3], s[4], s[5]);  
        }
        else
        {
            if(err_cunter == 0)
                fprintf(err, "Errors were found in the following lines:\n");
            
            fprintf(err, "%7d;", n_str + 1);
            err_cunter++;
            if(err_cunter % 5 == 0)
                fprintf(err, "\n");
        }
        
        n_str++;  // счетчик количества строк
    }
    fprintf(err, "\nTotal errors %d\n", err_cunter);

    fclose(in);
    fclose(err);

    calcul_aver_t(term); // вычисляем среднюю температуру

    print_static (err_in, result, term, err_cunter, month, year); // выводим на экран статистические данные и записываем в файл static.txt
    fclose(err_in);
    fclose(result);

    return 0;
}
