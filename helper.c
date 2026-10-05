#include "helper.h"

uint64_t get_ms(void)
{
    struct timespec time;
    if (clock_gettime(CLOCK_MONOTONIC_RAW, &time) != 0)
    {
        printf("Getting time failed\n");
        return 1;
    }   
    
    uint64_t timestamp = time.tv_sec * MS_PER_SEC + time.tv_nsec / NS_PER_MS;
    return timestamp;    
}

int count_words(char *text)
{
    size_t length = strlen(text);
    int words = 0;
    bool inside_word = false;

    for (size_t i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            // between words
            inside_word = false;
        }
        else
        {
            // in a word
            if (!inside_word)
            {
                words++;
                inside_word = true;
            }
        }
    }

    return words;
}

double calc_accuracy(char *typed, char *reference)
{
    size_t reference_length = strlen(reference);
    int mistakes = edit_distance(typed, reference);

    double accuracy = ((reference_length - mistakes) / (double) reference_length) * 100;
    return accuracy;
}
