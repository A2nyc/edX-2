/* 
Author: Ariel E.  
Date: Fall 2015
Class: CS50
File: Caesar.c 
 
*/ 
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <stdio.h>
#include <cs50.h>

// argumentcount contains argument length. argumentvector will contain the name of the program.
int main(int argumentcount, string argumentvector[])
{
    // initialize variable for key
    int Key = 0;
    
    // This will intialize the variable message to a variable.
    string message; 
    
    // This will check if argumentcount and argumentvector[] for correct entry: ./caesar and Key 
    // This will also return an error to the user if there is one.
    if (argumentcount < 2 || atoi(argumentvector[0]) < 0 || atoi(argumentvector[1]) < 0)
    
    { printf("Enter a single command line argument: which is a non-negative integer.\n"); return 1; } 
    
    // convert key to integer then store the key
    else { Key = atoi(argumentvector[1]); }
    
    // get user message
    message = GetString(); 
    
    // For loop to start cypher
    for (int i = 0, j = strlen(message); i < j; i++)
    {
        // Lowercase Letters
        if (islower(message[i]) && isalpha(message[i]))
        
        { message[i] = (message[i] - 'a' + Key) % 26 + 97; }
        
        // Upercase letters
        else if(isupper(message[i]) && isalpha(message[i]))
        
        { message[i] = (message[i] - 'A' + Key) % 26 + 65; }
        
        // print the encrypted characters
        printf("%c", message[i]); 
        
    }
    // Print a new line
    printf("\n"); 
     
    return 0; 
   
}
