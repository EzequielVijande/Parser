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

/*
 * 
 */
int CallbackTest(char*, char*, void*);


int main(int argc, char** argv) {
    int counter=0;
    int NumberOfParameters;
    NumberOfParameters= parseCmdLine(argc,argv, &CallbackTest, &counter);
    printf("\nNumber of parameters: %d", NumberOfParameters);
    return (EXIT_SUCCESS);
}

int CallbackTest(char* key, char* value, void* userdata)
{
    (*((int*)userdata))++;
    printf("\nKey %d: %s",*((int*)userdata), key);
    printf("\nValue %d: %s", *((int*)userdata),value);
    
    return 1;
}