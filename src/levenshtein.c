#include "levenshtein.h"

double fmin3(double x, double y, double z)
{
    return fmin(x, fmin(y,z));
}

int cost(char w1, char w2)
{
    int cost = 0;
    if (w1 == w2)
    {
        cost = 0;
    }
    else 
    {
        cost = 1;
    }

    return cost;
}

int edit_distance(char *word1, char *word2)
{
    // We want to turn word1 into word2

    // Length of words
    int w1_len = strlen(word1);
    int w2_len = strlen(word2);
   
    // initialize 2D array (+1 because base case)
    int cache[w1_len + 1][w2_len + 1];

    for (int i = 0; i < (w1_len + 1); i++)
    {
        // fill first column with 1, 2, 3... i(this corresponds to cost of deletion)
        cache[i][0] = i;
    }

    for (int j = 0; j < (w2_len + 1); j++)
    {
        // fill first row with 1, 2, 3 ... j (this corresponds to cost of insertion)
        cache[0][j] = j;
    }

    for (int i = 1; i <= w1_len; i++)
    {
        for (int j = 1; j <= w2_len; j++)
        {
            cache[i][j] = fmin3(
                (double) (cache[i - 1][j] + 1),
                (double) (cache[i][j - 1] + 1),
                (double) (cache[i - 1][j - 1] + cost(word1[i - 1], word2[j - 1]))
            );
        }
    }
    return cache[w1_len][w2_len];

}
