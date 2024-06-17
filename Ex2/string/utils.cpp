#include "utils.h"

void string_copy(char* d, char* s) {
    while (*s != '\0') {
        *d = *s;
        d++;
        s++;
    }
    *d = '\0'; 
}
int len(const char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

int compare(const char* s, const char* t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0; 
        }
    }
    return *s - *t;
}