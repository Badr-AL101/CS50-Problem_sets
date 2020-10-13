#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main (int argc,string argv[])
{
   
    if (argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int size = strlen(argv[1]);
    if (size != 26 ) // check if key's lenght is less than 26
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < size;i++) // check if key contains alphabets only
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Key must contain alphabets only.\n");
            return 1;
        }
    }
    for (int i = 0; i < size;i++) // check if key contains repeated characters
    {
        for (int j = i + 1; j < size;j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }
    string name = get_string("plaintext: ");
    int sizeName = strlen(name);
    for (int j = 0; j <= sizeName ;j++)
    {
        if(isupper(name[j]))
        {
            int map = (int) name[j] - 65; // assign the character a number to map it on the key
            if (islower(argv[1][map]))
            {
                argv[1][map] = argv[1][map] - 32; // convert the key character to uppercase,same as plaintext char
            }
             name[j]  = argv[1][map]; // switch the key char with the plaintext
        }
        else if (islower(name[j]))
        {
            int map = (int) name[j] - 97;
            if (isupper(argv[1][map]))
            {
                argv[1][map] = argv[1][map] + 32; // convert to lower,same as plaintext char
            }
            name[j]  = argv[1][map]; // switch the key char with the plaintext
        }
    }
    printf("ciphertext: %s\n",name);
}
