/* 
Author: Ariel E.  
Date: Fall 2015
Class: CS50
File: Initials.c 
 
*/ 

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    // Get users name
    string UserName = GetString();
    
    // This will turn the first letter into a Capital Letter
    printf("%c", toupper(UserName[0]));
   
    // A for loop to loop through the rest 
    for ( int i = 0, n = strlen(UserName); i < n; i++)
    {
        // This will check space and the end of the characters
        // print the rest of the initials and increment
        if ( UserName[i] == ' ' && UserName[i + 1] != '\0') 
        
        { printf("%c",toupper(UserName[i + 1])); i++; }
       
    }
    
    // This will print a new line after the initials.
    printf("\n"); 
}

