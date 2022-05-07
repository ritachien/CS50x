#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string t, int l);
int count_words(string t, int l);
int count_sentences(string t, int l);

int main(void)
{
    string texts = get_string("Text: "); // Get texts from user input

    int length = strlen(texts);                     // Counts length of text
    int letters = count_letters(texts, length);     // Declare numbers of letters in texts
    int words = count_words(texts, length);         // Declare numbers of words in texts
    int sentences = count_sentences(texts, length); // Declare numbers of sentences in texts

    float L = letters / (words / 100.0);   // Calculate numbers of letters per 100 words
    float S = sentences / (words / 100.0); // Calculate numbers of sentences per 100 words

    float index = 0.0588 * L - 0.296 * S - 15.8; // Declare Coleman-Liau index
    int grade = (int)round(index);               // Get Coleman-Liau index

    // Print result
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Count number of letters in Text
int count_letters(string t, int l)
{
    int counts = 0;
    for (int i = 0; i < l; i++)
    {
        if (isalpha(t[i]))
        {
            counts++;
        }
    }
    return counts;
}

// Count number of words in Text
int count_words(string t, int l)
{
    int counts = 1;
    for (int i = 0; i < l; i++)
    {
        if (isspace(t[i]))
        {
            counts++;
        }
    }
    return counts;
}

// Count number of sentences in Text
int count_sentences(string t, int l)
{
    int counts = 0;
    for (int i = 0; i < l; i++)
    {
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            counts++;
        }
    }
    return counts;
}
