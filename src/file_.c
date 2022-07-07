#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert_.h"

int existsDetect(char *fname) 
{
    FILE *pFile = NULL; 
    pFile = fopen(fname, "r");
    if (pFile != NULL) {
        fclose(pFile);
        return 1;
    } return 0;
}

int fileDetect(FILE *pFile) 
{
    char c = -2;
    do
    {
        c = fgetc(pFile);
    } while (((c == '.') || (c == '-') || (c == '/') || (c == ' ')) || (c == '\n'));
    if (c != EOF) {
        rewind(pFile);
        return 0;   //character file
    }
    rewind(pFile); 
    return 1;       //morse file
}

int convertToCharacterOverwrite(FILE *input, FILE *output)  //output is character file 
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int i = 0;
    
    //getline() tu dong cap phan bo nho de luu tru chuoi.
    while ((nread = getline(&line, &len, input)) != -1) {
        //Tach dong theo word by word.
        splitWord(line);
        fwrite(line, nread, 1, output);
    }

    //Giai phong vung nho cap phat boi ham getline().
    free(line); 
    fclose(input);
    fclose(output);
    return 0;
}

int convertToMorseOverwrite(FILE *input, FILE *ouput)
{

    return 1;
}

