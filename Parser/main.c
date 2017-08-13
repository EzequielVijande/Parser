/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ezequiel
 *
 * Created on August 13, 2017, 10:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

#define PRUEBA0
//#define PRUEBA1
//#define PRUEBA2
//#define PRUEBA3
//#define PRUEBA4

/*
 * 
 */
int CallbackTest(char*, char*, void*);

void PrintError(int code);


int main(int argc, char** argv) {
    int counter=0;
    int NumberOfParameters;
    int N_Arguments=argc;
    
#ifdef PRUEBA0
   char** Arguments=argv; 
#endif //PRUEBA0
    
#ifdef PRUEBA1
    N_Arguments= 1;
    char *Arguments[1]={"parser"};
    
#endif //PRUEBA1
    
#ifdef PRUEBA2
    N_Arguments= 4;
    char *Arguments[4]={"parser","-f","34gy5","-rt"};
    
#endif //PRUEBA2
    
#ifdef PRUEBA3
    N_Arguments= 3;
    char *Arguments[3]={"parser","-","34gy5"};
    
#endif //PRUEBA3
    
#ifdef PRUEBA4
    N_Arguments= 7;
    char *Arguments[7]={"parser","--aw","34gy5","ahchehv3","---54d","hu687","hjgdyt"};
    
#endif //PRUEBA4
    
    
    
    NumberOfParameters= parseCmdLine(N_Arguments,Arguments, &CallbackTest, &counter);
    if(NumberOfParameters<0)
    {
        PrintError(NumberOfParameters);
    }
    else
    {
        printf("\nNumber of parameters: %d\n", NumberOfParameters);
    }
    return (EXIT_SUCCESS);
}


int CallbackTest(char* key, char* value, void* userdata)
{
    (*((int*)userdata))++;
    printf("\nKey %d: %s",*((int*)userdata), key);
    printf("\nValue %d: %s", *((int*)userdata),value);
    
    return 1;
}
void PrintError(int code)
{
    switch(code)
        {
            case ERROR1:
                printf("\nMissing value.\n");
                printf("Entry format is '-x y', where x is the key and y the value.\n");
                printf("Single parameters whithout a key are also valid.\n");
                break;
                
            case ERROR2:
                printf("\nMissing Key.\n");
                printf("Entry format is '-x y', where x is the key and y the value.\n");
                printf("Single parameters whithout a key are also valid.\n");
                break;
                
            case ERROR3:
                printf("\nMissing Key And Value.\n");
                printf("Entry format is '-x y', where x is the key and y the value.\n");
                printf("Single parameters whithout a key are also valid.\n");
                break;
                
            case ERROR4:
                 printf("\nInvalid Arguments, please try again.\n");
                 break;
            
        }
}