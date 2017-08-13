/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"parser.h"

int parseCmdLine(int argc, char *argv[], pCallback p, void* userData)
{
    int ParamCounter=0;
    char *String;
    int i;
    int valid;
    if(argc!= 1)
    {
        for(i=1; i<argc; i++)
        {
            String= argv[i];
            if(String[0]!='-')
            {
               valid= p(NULL, String, userData); //si recibe un parametro pasa NULL como
                                           //clave y el parametro como value.
               if(!valid)
               {
                   return ERROR4;
               }
               ++ParamCounter;
            }
            else
            {
                
                if((++i)<argc)
                {
                    if(String[1]== '\0')
                    {
                        return ERROR2; //error de forma 2, hay valor pero no hay clave.
                    }
                    valid= p(String+1, argv[i], userData);
                    if(!valid)
                    {
                        return ERROR4;
                    }
                    ++ParamCounter;
                            
                            
                }
                else
                {
                    
                    if(String[1]== '\0')
                    {
                        return ERROR3; //error de forma 3, no hay valor ni hay clave.
                    }
                    return ERROR1; //error de forma 1 hay clave, pero  no hay valor
                    
                }
            }
            
        }
    }
    
    return ParamCounter;
    
}