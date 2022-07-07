#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void splitWord(char* str)//Da tach duoc theo tung ky tu
{
    char *p;
    //Tach chuoi lan dau tien
    p = strtok(str, "/ "); 
    //Tach chuoi tu lan thu 2 tro
    //Su dung strok den khi NULL tra ve.
    while(p != NULL) {
        //Doi so NULL trong ham strtok de tiep tuc tach chuoi ban dau.
        p = strtok(NULL, "/ ");
        if (p != NULL) {
        }
    }
}
