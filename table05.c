#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 50
#define MAX_LINE_LENGTH 1000

bool is_valid_identifier_char(char c) {
    return isalnum(c) || c == '_';
}

bool is_valid_identifier(char* identifier) {
    if (!isalpha(identifier[0])) {
        return false;
    }

    int i = 1;
    while (identifier[i] != '\0') {
        if (!is_valid_identifier_char(identifier[i])) {
            return false;
        }
        i++;
    }

    return true;
}

int main() {
    char filename[] = "test.c";
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    int num_identifiers = 0;
    char identifiers[MAX_IDENTIFIER_LENGTH][MAX_LINE_LENGTH];
    int line_numbers[MAX_IDENTIFIER_LENGTH];

    printf("Identifiers found:\n");
    printf("-------------------\n");
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char identifier[MAX_IDENTIFIER_LENGTH];
        int start_index = -1;
        int end_index = -1;
        int i = 0;
        while (line[i] != '\0') {
            if (is_valid_identifier_char(line[i])) {
                if (start_index == -1) {
                    start_index = i;
                }
                end_index = i;
            } else {
                if (start_index != -1) {
                    int len = end_index - start_index + 1;
                    if (len <= MAX_IDENTIFIER_LENGTH) {
                        strncpy(identifier, &line[start_index], len);
                        identifier[len] = '\0';
                        if (is_valid_identifier(identifier)) {
                            printf("| %-20s|\n", identifier);
                            strncpy(identifiers[num_identifiers], identifier, len);
                            identifiers[num_identifiers][len] = '\0';
                            line_numbers[num_identifiers] = line_num;
                            num_identifiers++;
                        }
                    }
                }
                start_index = -1;
                end_index = -1;
            }
            i++;
        }
        if (start_index != -1) {
            int len = end_index - start_index + 1;
            if (len <= MAX_IDENTIFIER_LENGTH) {
                strncpy(identifier, &line[start_index], len);
                identifier[len] = '\0';
                if (is_valid_identifier(identifier)) {
                    printf("| %-20s|\n", identifier);
                    strncpy(identifiers[num_identifiers], identifier, len);
                    identifiers[num_identifiers][len] = '\0';
                    line_numbers[num_identifiers] = line_num;
                    num_identifiers++;
                }
            }
        }
        line_num++;
    }
    fclose(fp);

    FILE* fp_output = fopen("identifiers.txt", "w");
    if (fp_output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(fp_output, "Identifiers found:\n");
    fprintf(fp_output, "-------------------\n");
    for (int i = 0; i < num_identifiers; i++) {
        fprintf(fp_output, "%d: %s\n", line_numbers[i], identifiers[i]);
    }
    fclose(fp_output);

    return 0;
}
