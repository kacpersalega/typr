#ifndef HELPER_H
#define HELPER_H 

// Defines
#define MAX_LENGTH  100
#define NS_PER_MS   1000000
#define MS_PER_SEC  1000
#define SEC_PER_MIN 60

// includes 
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include "levenshtein.h"

// functions
uint64_t get_ms(void);
int count_words(char *text);
double calc_accuracy(char *typed, char *reference);

#endif