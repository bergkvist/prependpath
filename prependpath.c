#define _GNU_SOURCE 2
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [value] [colon-separated-values]\n\n", argv[0]);
        return -1;
    }

    char *value = argv[1];
    char *tokens = argv[2];
    const char *separator = ":";

    char *result_buffer;
    size_t result_lenght;
    FILE *result = open_memstream(&result_buffer, &result_lenght);
    
    fprintf(result, "%s", value);
    char *token = strsep(&tokens, separator);
    while (token) {
        if (strcmp(value, token) != 0) {
            fprintf(result, "%s%s", separator, token);
        }
        token = strsep(&tokens, separator);
    }
    fprintf(result, "\n");

    fflush(result);
    fwrite(result_buffer, 1, result_lenght, stdout);
}
