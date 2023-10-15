#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

int preferences[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
}
pair;

pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

string candidates[MAX];

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool creates_cycle(int winner, int loser);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    pair_count = 0;
    int ranks[candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        printf("Rank %d: %s\n", i + 1, candidates[i]);
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %d: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 2;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_pairs(void)
{
    int index = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[index].winner = i;
                pairs[index].loser = j;
                pair_count++;
                index++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[index].winner = j;
                pairs[index].loser = i;
                pair_count++;
                index++;
            }
        }
    }
}

void sort_pairs(void)
{
    pair temp;

    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[i].winner][pairs[i].loser])
            {
                temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
}

void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!creates_cycle(pairs[i].winner, pairs[i].loser))
        {
            preferences[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

bool creates_cycle(int winner, int loser)
{
    if (winner == loser)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (preferences[loser][i])
        {
            if (creates_cycle(winner, i))
            {
                return true;
            }
        }
    }

    return false;
}

void print_winner(void)
{
    bool source;

    for (int i = 0; i < candidate_count; i++)
    {
        source = true;

        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[j][i])
            {
                source = false;
                break;
            }
        }

        if (source)
        {
            printf("%s\n", candidates[i]);
        }
    }
}