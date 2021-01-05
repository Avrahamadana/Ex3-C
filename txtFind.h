#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max_Lines 256
#define Max_Line_Length 256
#define Max_Word_Length 30
int initStringToSearch(char str[][Max_Line_Length]);
int checkTheWord(char whereWeLooking[] , char whatWeLooking[]);
int checkTheLine(char whereWeLooking[] , char whatWeLooking[]);
void printSimilar(char str[256][256] , int size );
