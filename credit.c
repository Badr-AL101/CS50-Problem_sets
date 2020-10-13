#include <cs50.h>
#include <stdio.h>
int main(void)
{
    long  input = 0 ;
    input = get_long("Number: ");
    long  second_last = 0;
    long  last = 0;
    long  sumk = 0;
    long  sumj = 0;
    int count = 0;
    for (long long int k = input; k > 0; k /= 100) // loop to check sum beginning with the second last digit
    {
        long long int mult = 0;
        second_last = (k % 100) / 10; // second last (first iteration)
        mult = (second_last * 2);
        long long int sep1 = mult % 10; // seperate the number,digit
        long long int sep2 = mult / 10; // seperate the number,tens
        long long int tot = (sep1 + sep2); 
        sumk += tot;
    }
    for (long long int j = input; j > 0; j /= 100) // loop to check sum beginning with the last digit
     {
        long long int multj = 0;
        last = j % 10;  // last digit (first iteration)       
        sumj += last;
    }
    long long int totalSum = sumk + sumj;
    long long int checkSum = totalSum % 10;
    long long int cpyinput = input; // copy the input into another variable to identify how many digits
    while (cpyinput != 0) // loop to identify how many digits
    {
        cpyinput /= 10;
        count++;
    }
    int count2 = count - 2;
    long long int power = 10;
    while (count2 > 1)
    {
        power *= 10;
        count2--;
    }
    long long int first_2_Digits = input / power;
    if ((first_2_Digits == 34 || first_2_Digits == 37) && checkSum == 0 && count == 15)
    {
         printf("AMEX\n");
    }
    else if ((first_2_Digits == 51 || first_2_Digits == 52 || first_2_Digits == 53 || first_2_Digits == 54 || first_2_Digits == 55) && checkSum == 0 && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (((first_2_Digits / 10) == 4) && checkSum == 0 && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
