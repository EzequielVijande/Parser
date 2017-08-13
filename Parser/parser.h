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

#define ERROR -1

typedef int (*pCallback)(char*, char*, void *);

int parseCmdLine(int argc, char *argv[], pCallback p, void* userData);

#endif /* PARSER_H */

