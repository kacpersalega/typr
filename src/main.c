#include <stdio.h>
#include "helper.h"
#include "levenshtein.h"

int main(void)
{
    char *txt = "The quick brown fox jumps over the lazy dog";

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
    double typed_accuracy = calc_accuracy(buff, txt);

    printf("\nTyping speed: %.2f (wpm)\n", typing_speed);
    printf("Accuracy: %.1f %% \n", typed_accuracy);
}