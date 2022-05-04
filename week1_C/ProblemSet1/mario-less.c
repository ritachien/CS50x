#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Get valid height from user
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // For each row
    for (int i = 1; i <= height; i++)
    {
        // For each column of space
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        // For each column of block
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Jump to next row
        printf("\n");
    }
}
