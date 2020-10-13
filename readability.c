#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
double count_letters(string a);
double count_sentences(string x);
int main(void)
{
    string test = get_string("text: ");
    double count_words = 0;
    for(int i = 0;i < strlen(test);i++)
    {
        if(test[i] == ' ')
        count_words++;
    }
    count_words += 1;//add the last word since it is not followed by a space
    printf("%f\n",count_letters(test));
    printf("%f\n",count_sentences(test));
    printf("%f\n",count_words);
    double per100 = count_words / 100;
    double index = 0.0588 *   ( (count_letters(test) /count_words) * 100)  - 0.296 * ( (count_sentences(test) /count_words) * 100)  - 15.8;
    double rounded = round(index);
    int indexInt = rounded;

    if (indexInt < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indexInt > 1 && indexInt < 16)
    {
        printf("Grade %d\n",indexInt);
    }
    else if (indexInt >= 16)
    {
        printf("Grade 16+\n");
    }
    //printf("Grade %lf\n",index);
    return 0;
}
double count_letters(string a)
{
    double count = 0;
    for(int i = 0;i < strlen(a);i++)
    {
        int conv = a[i]; // convert to ascii
        if (isalpha(conv) !=  0)
        count++;
    }

    return count;
}
double count_sentences(string x)
{
    double count = 0;
    for(int i = 0; i < strlen(x);i++)
    {
        int conv = x[i];
        switch(conv)
        {
            case 33:
            count++;
            break;
            case 46:
            count++;
            break;
            case 63:
            count++;
            break;
            default:
            break;
        }
    }
    return count;
}
