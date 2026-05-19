#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include<string.h>
typedef unsigned long count_t;


char *arg;
count_t ch_count = 0;
count_t w_count = 0;
count_t nl_count = 0;
 char c;


void show (char *arg,char *file, count_t ccount, count_t wcount, count_t lcount)
{

    
        switch (c) {
        case 'l': 
           printf("%6lu\n", nl_count);
            break;
        case 'w': 
           printf("%6lu\n", w_count);
            break;
        case 'c': 
           printf("%6lu\n", ch_count);
            break;
        default:
            printf ("%6lu %6lu %6lu %s\n", lcount, wcount, ccount, file);
            break;
        }
    
 


 
}



int count(FILE *fptr){
    char ch;
    int word= 0;
    while ((ch = fgetc(fptr)) != EOF)
    {
        ch_count++;
        if(ch == '\n'){
            nl_count++;
            if(word){
                w_count++;
                word=0;
            }
        }else if (ch == ' ' || ch == '\t'){
           if(word){ 
            word = 0;
            w_count++;
           }
        }else{
            word = 1;
        }  
    }
    if (word) {
        w_count++;
    }

    fclose(fptr);
    return nl_count, w_count, ch_count;

}



void file_process(char *file){
    FILE *fptr = fopen(file, "r");


    if(!fptr){
        printf("cannot open file");
    }else{
       // printf("file opened successfully\n");
    }
    nl_count, w_count, ch_count = count(fptr);
    show(arg, file, ch_count, w_count, nl_count);

}




int main(int argc, char **argv){
   
     for (int i = 0; i < argc; i++)
    {
        if (i == 1)
        {
            arg = argv[i];
            c = arg[i];
           //printf("%c\n", c);
        }

    }   
    if(argc>=2){
        file_process(argv[argc-1]);
    }
}