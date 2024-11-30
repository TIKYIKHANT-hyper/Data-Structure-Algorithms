#include <stdio.h>

int isVowel(char c);
int vowelCheck(char *str, char *upstr);
int getLenArrStr(char *str);

int main() {
    char x[60] = "apple,orange,lemon,pineapple,avocado.";
    char test[100];
    int res = vowelCheck(x, test);
    printf("Result: %s\n", test);
    printf("Words Count: %d\n", res);
    return 0;
}

int getLenArrStr(char *str) {
    unsigned int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int isVowel(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; // Convert uppercase to lowercase
        }
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    return 0;
}

int vowelCheck(char *str, char *upstr) {
    int first = 0, last = 0;
    int wordCount = 0;
    char *start = NULL;

    while (*str != '\0') {
        if (*str != ',' && *str != ' ' && start == NULL) {
            start = str;
            first = isVowel(*str);
        }

        if (*str == ',' || *str == '.') {
            if (start != NULL) {
                char *end = str - 1;
                last = isVowel(*end);

                if (first == 1 && last == 1) {
                    while (start <= end) {
                        *upstr++ = *start++;
                    }
                    *upstr++ = ',';
                    wordCount++;
                }
                start = NULL;
                first = 0;
                last = 0;
            }
        }
        str++;
    }

    if (upstr != NULL && *(upstr - 1) == ',') {
        *(upstr - 1) = '\0';
    } else {
        *upstr = '\0';
    }

    return wordCount;
}
