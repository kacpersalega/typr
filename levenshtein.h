#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H 

// Includes 
#include <stdio.h>
#include <string.h>
#include <math.h>

double fmin3(double x, double y, double z);
int cost(char w1, char w2);
int edit_distance(char *word1, char *word2);

#endif