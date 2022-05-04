#include <cs50.h>
#include <stdio.h>

int digits_sum(int number);
bool luhn_check(long num);
void card_company(long card_num);

int main(void)
{
    long card_num;

    do
    {
        card_num = get_long("Credit card numbers without hyphens: ");
    }
    while (card_num <= 0);

    // Check Luhn’s Algorithm
    bool is_luhn_valid = luhn_check(card_num);

    // If card number valid, print card company. Otherwise, print INVALID.
    if (!is_luhn_valid)
    {
        printf("INVALID\n");
    }
    else
    {
        card_company(card_num);
    }
}

// Function: check card company
void card_company(long num)
{
    // AMEX(15 digits start with 34 or 37)
    // MASTER(16 digits start with 51-55)
    // VISA(13/16 digits start with 4)

    if ((num >= 34e13 && num < 35e13) || (num >= 37e13 && num < 38e13))
    {
        printf("AMEX\n");
    }
    else if (num >= 51e14 && num < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((num >= 4e12 && num < 5e12) || (num >= 4e15 && num < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Function: check Luhn’s Algorithm
bool luhn_check(long num)
{
    int odd_sum = 0;
    int even_sum = 0;
    int total;

    while (num > 0)
    {
        odd_sum += num % 10;
        num /= 10;

        even_sum += digits_sum(num % 10 * 2);
        num /= 10;
    }
    total = odd_sum + even_sum;

    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function: check digit sum after mutiply by 2
int digits_sum(int number)
{
    return number / 10 + number % 10;
}
