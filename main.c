#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <sys/time.h>
#include <unistd.h>

// return current time in microseconds
int64_t current_usec(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

int mystrlen(const char *str) {
    return *str ? 1 + mystrlen(str + 1) : 0;
}

// copy string from src to dest
// returns dest
char * mystrcpy (char *dest, const char *src) {
    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    return dest;
}

// returns 0 if mystrlen(s1) == mystrlen(s2) and for 0 <= i < mystrlen(s1) s1[i] == s2[i]
// else, return non-zero
int mystrcmp(char *s1, char *s2) {
    if(!*s1 && !*s2) {
        return 0;
    }
    else if(*s1 != *s2){
        return 1;
    }
    return mystrcmp(s1 + 1, s2 + 1);
}
// dest = "asdf";
// src = "zxcv";
//
// dest = "asdfzxcv";
char *mystrcat(char *dest, const char *src) {
    char *tmp = dest;
    while(*dest) {
        dest++;
    }
    mystrcpy(dest, src);
    return tmp;
}

// Make random character
char rand_char(void) {
    // 0 <= randnum < RAND_MAX
    int randnum = rand();
    randnum = randnum % 93;
    randnum += 33;
    return randnum;
}

// Fill random charactor in dest, with length len
// if len == 0, mystrlen(dest) == 0
char *fill_rand_str(char *dest, int len) {
    int l;
    for(l = 0; l < len; l++){
        dest[l] = rand_char();
    }
    dest[len]= '\0';
    return dest;
}

int main(void) {
    srand(current_usec());

    const int len = 128;
    char src[len];
    *src = '\0';

    mystrcat(src, "hello, ");
    mystrcat(src, "world");
    printf("%s\n", src);

    return 0;
}
