#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include<string.h>


#define MAX 10000
char *arg;
char c;
FILE *fptr;
int concat= 0;





void file_process_create(char *file){
       fptr = fopen(file,"w");
       printf("file created successfully\n");
       char file_content[MAX];
       fgets(file_content, MAX, stdin);
       fputs(file_content, fptr);
       fclose(fptr);

      
    }

void file_process_op(char *file){
     fptr = fopen(file, "rw");
       printf("file opened successfully\n");
}
void show (char *file)
{


   
        switch (c) {
        case 'a': 
            fptr = fopen(file,"w");
            char file_content[MAX];
            fgets(file_content, MAX, stdin);
            fputs(file_content, fptr);
            fclose(fptr);
            break;
        case 'c': 
           file_process_create(file);
            break;
        case 'e': 
            printf("ref\n");
            break;
        default:
            printf ("fe");
            break;
        }
 
}



int main(int argc, char **argv){
   
     for (int i = 0; i < argc; i++)
    {
        if (i == 1)
        {
            arg = argv[i];
            c = arg[i];
            printf("%c\n", c);
            printf("%s\n", arg);
        }

    }   
    if(argc>=2){

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

       show(argv[argc-1]);
    }
}