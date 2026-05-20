#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define MAX 10000
char *arg;
char c;
FILE *fptr;
int concat = 0;


void concatenate_files(char *file1, char *file2){
   FILE *fptr1 = fopen(file1, "r");
   FILE *fptr2 = fopen(file2, "w");
   char ch;
    while ((ch = fgetc(fptr1)) != EOF)
    {
        fputc(ch, fptr2);   
     }  
       fclose(fptr2);
        fclose(fptr1);
        

}
void file_process_create(char *file)
{
    fptr = fopen(file, "w");
   // printf("file created successfully\n");
    char file_content[MAX];
    fgets(file_content, MAX, stdin);
    fputs(file_content, fptr);
    fclose(fptr);
}

void read_file(char *file)
{
    fptr = fopen(file, "r");
    //printf("file opened successfully\n");
}

void show(char *file, char *file2)
{

    switch (c)
    {
    case 'a':
        fptr = fopen(file, "w");
        char file_content[MAX];
        fgets(file_content, MAX, stdin);
        fputs(file_content, fptr);
        fclose(fptr);
        break;
    case 'c':
        file_process_create(file);
        break;
    case '>':
       concatenate_files(file, file2);
        break;
    default:
        printf("fe");
        break;
    }
}

void display(FILE *file, char *argv, int argc)
{

    char ch;
    while ((ch = fgetc(fptr)) != EOF)
    {
        putchar(ch);
    }

    fclose(fptr);
}





int main(int argc, char **argv)
{

    for (int i = 0; i < argc; i++)
    {
        if (i == 1)
        {
            arg = argv[i];
            c = arg[i];
            // printf("%c\n", c);
          //  printf("%s\n", arg);
        }
    }
    if (argc > 2)
    {

        /* if(arg == "cc"){
             printf("Concatenation");

         }else if (arg == "-c")
         {
             file_process(argv[argc-1] );
         }
         else{
           file_process(argv[argc-1]);
         }

        */

        show(argv[argc -2],argv[argc - 1]);
    }
    else if (argc == 2)
    {
        read_file(argv[argc - 1]);
        display(fptr, *argv, argc);
    }
}