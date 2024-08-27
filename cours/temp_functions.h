#ifndef FF_H_FUNCTIONS
#define FF_H_FUNCTIONS

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>


struct stt
{
    float aver_t;
    uint32_t counter;
    int32_t sum_aver_t;
    int8_t min_t;
    int8_t max_t;
};

FILE* in;
FILE* err;
FILE* err_in;
FILE* result;

int reader(FILE*in, int data[]);
int err_or(int data[], int year);
void save_m_struct(struct stt *term, int *data);
void calcul_aver_t(struct stt *term);
int define_year(FILE*in);
void print_argum(void);
int menu_arg(char* name_file, int* month);
void print_static (FILE* err_in, FILE* result, struct stt *term, int err_cunter, int month, int year);


#endif
