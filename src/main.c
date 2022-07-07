#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "file_.h"
#include "convert_.h"

#define ERR(x) do {printf("Error: %s could not be opened.\n", argv[x]); exit(EXIT_FAILURE); \
} while (0);

int main(int argc, char *argv[])
{
   if (argc != 3) {
      printf("Usage: morse <input file> <output file>\n");
      exit(EXIT_FAILURE);
   }  

   int test = existsDetect(argv[2]); 
   char ch;
   FILE *input = NULL;
   input = fopen(argv[1],"r");
   //Kiem tra loi khi mo file input.
   if (input == NULL){ERR(1)};

   FILE *output = NULL;
   output = fopen(argv[2], "w+");
   //Kiem tra loi khi mo file output. 
   if (output == NULL){ERR(2)};

   int check = fileDetect(input);  

   if (test == 1) { //test = 1: file output da ton tai.

      switch (check) //Kiem tra file input la loai file nao.
      {
      case 1:  //input file la file Morse.
         printf("Warning: FILENAME already exists. Do you wish to overwrite (y,n)? ");
         scanf("%c", &ch);
         if (ch == 'y'){convertToCharacterOverwrite(input, output);}
         break;   
      case 0:  //input file la file Character.
         printf("Warning: FILENAME already exists. Do you wish to overwrite (y,n)? ");
         scanf("%c", &ch);
         //if (ch == 'y') {morseConvertOverwrite(input, argv[2]);}
         break;
      }

   } else if (test == 0) { //test = 0: file output chua ton tai, tao file output.

      switch (check) //Kiem tra file input la loai file nao.
      {
      case 1:   //input file la file Morse.
         printf("file Morse\n"); 
         break;   
      case 0:   //input file la file Morse.
         printf("file character\n");
         break;
      }
   } 
  
   return 0;
}
