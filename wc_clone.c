// #include <stdlib.h>
// #include <string.h>
#include <stdio.h>
#include <ctype.h>
//#define COUNT 1024 //I used to store the whole file in memory in the beginning, now this is the max. array size



int main(int argc, char const *argv[]) {
if (argc != 2){
  printf("Something wrong with the arguments. Did you specify ONE filename?\n");
  return 0;
}
FILE *file = fopen(argv[1], "r");
if (file == NULL){printf("Either no file there or something decided not to work\n"); return 0;}
unsigned int chars = 0, words = 0, digits = 0, lines = 0;
int in_space = 1;
int c, last_c = '\n';
// const int COUNT = 1024;
// char buffer[COUNT];

do {
  c = fgetc(file);
  last_c = c;
/*  // separated words between lines and double spaces
  if ((c == ' ') && (buffer[n+1] != ' ')) {words++;}
  if ((c == '-') && (buffer[n+1] == '\n')) {words--;}*/
  if (isdigit(c)) {digits++;}
  if (c == ' ')   {words++;}
  if (c == '\n')  {lines++;}

  words += in_space;
  in_space = 0;
  if(c != EOF){
    chars++;
    printf("%c", c);
  }
}
while ((c != 0) && (c != EOF));

switch (lines){
  case 1:
  printf("\nOne-liners are never old.\n");
  break;
  case 14:
  printf("\nA beautiful sonnet with these stats:\n");
  break;
  default:
  printf("\nlines, words, total characters and digits in file (respectively):\n");
}
printf("\n %3u %3u %3u %3u\n", lines, words, chars, digits);
fclose(file);
return 0;
}
