#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define Max 9
// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[Max];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
//bool quit();
int main(int argc,string argv[])
{
    int max = 9; //max voters allowed

   // Check for invalid usage
    if (argc < 3)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    if (argc != 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > max)
    {
        printf("Maximum number of candidates is %i\n", max);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}


// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count;i++)
    {
        if (strcmp (name,candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}


// Print the winner (or winners) of the election
void print_winner(void)
{
    int temp1;
    string temp;
    for(int i = 0;i < candidate_count;i++)
    {
        for(int j = i + 1; j< candidate_count;j++)
        {
            if (candidates[i].votes < candidates[j].votes)
            {
                temp1 = candidates[i].votes; //place the lower votes in temp1
                temp = candidates[i].name;//place the name with lower votes in temp
                candidates[i].votes = candidates[j].votes;// swap the larger number with the smaller
                candidates[i].name = candidates[j].name; // swap the name with larger votes
                candidates[j].votes = temp1; //swap the lower votes
                candidates[j].name = temp;//swap the name with lower votes
            }
        }
    }
    for(int g = 0;g < candidate_count;g++)
    {
    if (candidates[0].votes == candidates[g].votes) // check for a tie
    {
        printf("%s\n",candidates[g].name);
    }
    }

    return;
}

