#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Get valid int of height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // For each row
    for (int i = 1; i <= height; i++)
    {
        // For each left part of column(space)
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        // For each left part of column(block)
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        // For each spaces between column
        printf("  ");
        // For each right part of column(block)
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
