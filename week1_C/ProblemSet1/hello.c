#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get user's name
    string name = get_string("What's your name? ");
    
    // Greet to user with name provided
    printf("hello, %s\n", name);
}
