#include <stdio.h>
#include <stdlib.h>

int isVowel(char c);
int vowelCheck(char *str);


int main() {
    char x[60] = "Apple,Orange,Lemon,pineapple.";
    int res = vowelCheck(x);
    printf("%d\n", res);
    return 0;
}

int getLenArrStr(char *str) {
    unsigned int count = 0;
    while(*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int arrInitStr(char *str) {
    int len = getLenArrStr(str);

}
int isVowel(char c) {
    if( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) {
        if(c >= 65 && c <= 90) {
            c = c + 32;
        }
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return 1;
        } else {
            return 0;
        }
    }else {
        return -1;
    }
}

int vowelCheck(char *str) {
    int first = 0;
    int last = 0;
    int wordCount = 0;
    int firstCheck = 1;
    int charCount = 0;
    int charCurWord = 0;
    while(*str != '.') {
        if(isVowel(*str) && firstCheck == 1) {
            first = 1;
            firstCheck = 0;
        }
        if(*str == ',') {
            str--;
            if(isVowel(*str)){
                last = 1;
                str++;
            }
            else {
                last = 0;
                str++;
            }
        if(first == 1 && last == 1) {
            wordCount++;
            first = 0;
            last = 0;
            firstCheck = 1;
            charCurWord = 0;
        }
        else {
            first = 0;
            last = 0;
            firstCheck = 1;
            charCount = charCount - charCurWord;
            charCurWord = 0;
        }
            str++;
        }
        else
        {
            str++;
            charCurWord++;
            charCount++;
        }
    }
    return wordCount;
}