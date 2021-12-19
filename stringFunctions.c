#include<stdio.h>
#include<string.h>


//A function that receives a character and returns its gematric value.
int gematricValue(char c){
    if(c >= 'A' && c <= 'Z'){
        return (c - 'A' + 1);
    }
    if(c >= 'a' && c <= 'z'){
        return (c - 'a' + 1);
    }
    return 0;
}

//A function that prints all the minimum sequences in
// the text with a gematric value identical to the value of the captured word.

int gematricSeq(char word[], char text[], int wordLen, int textLen){

    int tag = 0;
    int wordGeValue = 0;

    //finding the gematric value of the word
    for (int i = 0; i < wordLen; i++)
    {
        wordGeValue += gematricValue(word[i]);
    }

    for (int i = 0; i < textLen; i++)
    {
        int tempGeValue = 0;
        // printf("%d\n", (gematricValue(text[i])));
        if (gematricValue(text[i]) != 0)
        {
            for (int j = i; (j < textLen) && (tempGeValue <= wordGeValue); j++)
            {
                tempGeValue += gematricValue(text[j]);
                if (tempGeValue == wordGeValue)
                {
                    if (tag == 1) printf("~");
                    tag = 1;
                    for (int k = i; k <= j; k++)
                    {
                        printf("%c", text[k]);
                    }
                    break;  
                } 
            }  
        }   
    }
    return 0;   
}

//A function that receives a character and returns its atbash code.
char atbashCode(char c){
    if(c >= 'A' && c <= 'Z'){
        return ('A' + 'Z' - c);
    }
    if(c >= 'a' && c <= 'z'){
        return ('a' + 'z' - c);
    }
    return c;
}

int isAtbash(char word[], char text[], int wordLen, int textLen, int index, int* tag){
    
    int i = index;
    int j = 0;

    while (j < wordLen && i < textLen)
    {
        if (text[i] == ' ')
        {
            i++;
        }

        else if (text[i] == word[j])
        {
            j++, i++;
        }

        else break; 
    }

    if (j == wordLen)
    {
        if (*tag == 1) printf("~");
        *tag = 1;
        for (int k = index; k < i; k++)
        {
            printf("%c", text[k]);
        }
    }
    
    return 0;
}

int atbashSeq(char word[], char text[], int wordLen, int textLen){

    char wordAtb[wordLen];
    char wordAtbRev[wordLen];
    int tag = 0;
    int *pointTag = &tag;

    for (int i = 0, j = wordLen-1 ; i < wordLen; i++, j--)
    {
        wordAtb[i] = atbashCode(word[i]);
        wordAtbRev[i] = atbashCode(word[j]);
    }

    for (int i = 0; i < (textLen-wordLen+1); i++)
    {
        if (text[i] == wordAtb[0])
        {
            isAtbash(wordAtb, text, wordLen, textLen, i, pointTag);
        }
        if (text[i] == wordAtbRev[0])
        {
            isAtbash(wordAtbRev, text, wordLen, textLen, i, pointTag);
        } 
    }
    return 0; 
}

int isAnagram(char word[], char text[], int wordLen, int textLen, int index, int* tag){

    int i = index;
    int j = 0;
    char copyWord[wordLen+1];
    strcpy(copyWord, word);

    while (j < wordLen && i < textLen)
    {
        if (text[i] == ' ')
        {
            i++;
        }

        else if (strchr(copyWord, text[i]) != NULL)
        {
            char* remove = strchr(copyWord, text[i]);
            *remove = ' '; 
            j++, i++;
        }

        else break; 
    }

    if (j == wordLen)
    {
        if (*tag == 1) printf("~");
        *tag = 1;
        for (int k = index; k < i; k++)
        {
            printf("%c", text[k]);
        }
    }

    return 0;
}

int anagramSeq(char word[], char text[], int wordLen, int textLen){

    int tag = 0;
    int *pointTag = &tag;

    for (int i = 0; i < (textLen-wordLen+1); i++)
    {
        if (strchr(word, text[i]) != NULL)
        {
            isAnagram(word, text, wordLen, textLen, i, pointTag);
        }
        
    }

    return 0;
}
