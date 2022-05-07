#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check if provide only one command-line argument
    if (argc != 2)
    {
        printf("Usage ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);

    // Check if key's length is 26
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < key_length; i++)
        {
            // If not alphabetic, return error message
            if (!isalpha(key[i]))
            {
                printf("Every key must be an alphabet.\n");
                return 1;
            }

            // If same alphabet repeat in key, return error message
            for (int j = 0; j < i; j++)
            {
                if (key[i] == key[j])
                {
                    printf("Every alphabet in key must be unique.\n");
                    return 1;
                }
            }
        }
    }

    // Get plaintext from user input
    string plaintext = get_string("plaintext:  ");
    int plaintext_length = strlen(plaintext);

    // Cipher plaintext by substitution
    printf("ciphertext: ");

    for (int i = 0; i < plaintext_length; i++)
    {
        int index;

        // If character is uppercase, print cipher in uppercase
        if (isupper(plaintext[i]))
        {
            index = plaintext[i] - 65;
            printf("%c", toupper(key[index]));
        }
        // If character is lowercase, print cipher in lowercase
        else if (islower(plaintext[i]))
        {
            index = plaintext[i] - 97;
            printf("%c", tolower(key[index]));
        }
        // If character is not alphabetic, print original character
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
