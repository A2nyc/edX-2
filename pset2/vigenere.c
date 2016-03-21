/* 
Author: Ariel E.  
Date: Fall 2015
Class: CS50
File: vigenere.c 
 
*/ 

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(int argumentcount, string argumentvector[])
{
    // Make a counter
    int counter = 0; 
    // Create a variable that stores the key
    string key = argumentvector[1];
    // Stores user message
    string message = NULL;
    // This will make the last character be examined.
    int lastC = 0; 
    
   

   
    // This will validate the arguments by warning the user
    if (argumentcount != 2)
    
    { printf("You must enter a single command-line argument: \n"); return 1; }
    
    // This will verify the keyword is from A-Z
    for ( int n = 0; n < strlen(key); n++) 
    {
         // Will check if it is not alphabetical
        if ( !isalpha(argumentvector[1][n]) )
        
        { printf("you've entered non-alphabetical chars\n"); return 1; }
        
    }
         
    // This will loop through as long as the message is NULL or empty.
    do 
    {
        message = GetString(); 
    }
    while(message == '\0'); 
     
    
    // This will loop through the message and change up the string 
    // Will be using functions from imported libraries
    for (int i = 0, j = strlen(message); i < j; i++)
    { 
    
        // This will validate
        if (isalpha(message[i]))
        {
            // To set counter to modulo length of keyword
            counter = lastC % strlen(key);
            
            // LOWERCASE preservation
            if (islower(message[i]))
            {
                if (islower(key[counter]))
                
                { message[i] = ((message[i] - 'a' + key[counter] - 97) % 26) + 97; printf("%c", message[i]); }
                
                else
                
                { message[i] = ((message[i] - 'a' + key[counter] - 65) % 26) + 97; printf("%c", message[i]); }
            }
            
            // UPPERCASE preservation
            if (isupper(message[i]))
            {
                if (islower(key[lastC]))
                
                { message[i] = ((message[i] - 'A' + key[counter] - 97) % 26) + 65; printf("%c", message[i]); }
                
                else
                
                { message[i] = ((message[i] - 'A' + key[counter] - 65) % 26) + 65; printf("%c", message[i]); }
           
            }
            
        // increment last characters by 1    
            lastC++;
        }
        
        // Prints encrypted message
        else
        { printf("%c", message[i]); }
    }
    
    // Prints a new line
    printf("\n");
    
    
    // No errors exist! 
    return 0; 
}
