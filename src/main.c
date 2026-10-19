#include <stdio.h>
#include "helper.h"
#include "levenshtein.h"

int main(void)
{
    FILE *fp;
    char arr[NUMBER_OF_LINES][MAX_LENGTH];
    char buff[MAX_LENGTH];
    int linecount = 0;
    
    fp = fopen("assets/quotes.txt", "r");

    while (fgets(buff, sizeof buff, fp) != NULL) 
    {
        buff[strcspn(buff, "\n")] = '\0';
        strcpy(arr[linecount], buff);
        linecount++; 
    }

    uint64_t current_time = get_ms();
    int random_number = (int)current_time % 85;

    printf("Type: %s\n", arr[random_number]);

    
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
    double typed_accuracy = calc_accuracy(buff, arr[random_number]);

    printf("\nTyping speed: %.2f (wpm)\n", typing_speed);
    printf("Accuracy: %.1f %% \n", typed_accuracy);
}