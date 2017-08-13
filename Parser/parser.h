/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   parser.h
 * Author: ezequiel
 *
 * Created on August 13, 2017, 2:56 PM
 */

#ifndef PARSER_H
#define PARSER_H

#include<stdio.h>
#include<stdlib.h>

#define ERROR1  -1
#define ERROR2  -2
#define ERROR3  -3
#define ERROR4  -4

typedef int (*pCallback)(char*, char*, void *);

int parseCmdLine(int argc, char *argv[], pCallback p, void* userData);
//Funcion que recibe un arreglo de argumentos y la cantidad de los mismos 

#endif /* PARSER_H */

