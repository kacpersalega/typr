#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

char *txt = "The quick brown fox jumps over the lazy dog";

// Defines
#define MAX_LENGTH  100
#define NS_PER_MS   1000000
#define MS_PER_SEC  1000
#define SEC_PER_MIN 60

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

double calc_accuracy(char *reference, char *typed)
{
    size_t reference_length = strlen(reference);
    int mistakes = 0;
    for (size_t i = 0; i < reference_length; i++)
    {
        if (reference[i] != typed[i])
        {
            mistakes++;
        }
    }

    double accuracy = ((reference_length - mistakes) / (double) reference_length) * 100;
    return accuracy;
}

int main(void)
{
    printf("Type: %s\n", txt);

    char buff[MAX_LENGTH];
    
    uint64_t start_time;
    uint64_t end_time;

    start_time = get_ms();

    if(fgets(buff, sizeof(buff), stdin) != NULL)
    {
        buff[strcspn(buff, "\n")] = '\0'; // get rid of trailing newline char
    }

    end_time = get_ms();

    uint64_t delta_ms = end_time - start_time;

    int words_count = count_words(buff);
    double typing_speed = words_count / (delta_ms / (double) MS_PER_SEC / (double) SEC_PER_MIN);
    double typed_accuracy = calc_accuracy(txt, buff);

    printf("\nTyping speed: %.2f (wpm)\n", typing_speed);
    printf("Accuracy: %.1f %% \n", typed_accuracy);
}