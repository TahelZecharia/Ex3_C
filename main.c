#include<stdio.h>
#include <string.h>
#include"stringFunctions.h"
// #include"my_mat.h"

#define TXT 1024
#define WORD 30

int main(){

    char word[WORD];
    char text[TXT];
    int wordLen = 0;
    int textLen = 0;
    char c;

    //scan the input:
    scanf("%[^\n^\t^' ']", word);
    scanf("%c", &c);
    scanf("%[^~]", text);

    wordLen = strlen(word);
    textLen = strlen(text);

    // printf("%s\n", word);
    // printf("%s\n", text);
    // printf("%d\n", wordLen);
    // printf("%d\n", textLen);
    
    printf("Gematria Sequences: ");
    gematricSeq(word, text, wordLen, textLen);

    printf("\nAtbash Sequences: ");
    atbashSeq(word, text, wordLen, textLen);
    
    printf("\nAnagram Sequences: ");
    anagramSeq(word, text, wordLen, textLen);

    return 0;
}