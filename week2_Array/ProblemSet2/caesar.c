#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Expect input: ./caesar key
    // Check if provide more or less than one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // If argv is not digit, return error message
    int argv_length = strlen(argv[1]);
    for (int i = 0; i < argv_length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert key from string to integer and check if it's non-negtive
    int key = atoi(argv[1]) % 26;

    // Get plaintext from user input
    string plaintext = get_string("Plaintext:  ");

    // Cipher: shift alphabet by key position provided
    printf("ciphertext: ");

    int plaintext_length = strlen(plaintext);
    for (int i = 0; i < plaintext_length; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = (plaintext[i] - 65 + key) % 26 + 65;
            printf("%c", plaintext[i]);
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = (plaintext[i] - 97 + key) % 26 + 97;
            printf("%c", plaintext[i]);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
