#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, valid = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    if (!isalpha(str[0])) {
        valid = 0;
    }

    for (i = 1; i < len; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("%s is a valid identifier.\n", str);
    } else {
        printf("%s is not a valid identifier.\n", str);
    }

    return 0;
}
