#include "txtFind.h"
int initStringToSearch(char str[][Max_Line_Length])
{
    char c;
    int line = 0;
    int charCount = 0;

    while (scanf("%c", &c) != EOF)
    {
        if (c == '\n')
        {
            str[line++][charCount] = c;
            charCount = 0;
        }
        else
        {
            str[line][charCount++] = c;
        }
    }
    return line;
}
int checkTheWord(char whereWeLooking[] , char whatWeLooking[]){ //------->b
    int lenghtWhere = strlen(whereWeLooking);
    int lengthWhat = strlen(whatWeLooking);
    int flag = 0;
    int index = 0;
    for(int i = 0;i<lenghtWhere && flag == 0 ; i++){
        if(whereWeLooking[i] == whatWeLooking[index]) index = index + 1;
        if(index == lengthWhat) flag = 1;
    }
    if(flag==1 && (lenghtWhere-1)<=(lengthWhat))
    {
        printf("%s\n",whereWeLooking);
        return 1;
    }else return 0;
}



int checkTheLine(char whereWeLooking[] , char whatWeLooking[]){//------>a
    int lenghtWhere = strlen(whereWeLooking);
    int lengthWhat = strlen(whatWeLooking);
    int flag = 0;
    int index = 0;
    for(int i = 0;i<lenghtWhere && flag == 0 ; i++){
        if(whereWeLooking[i] == whatWeLooking[index]) index = index + 1;
        if(index == lengthWhat) flag = 1;
    }
    if(flag==1 && (lenghtWhere-1)<=(lengthWhat)) return 1;
    else return 0;
}





void printSimilar(char str[256][256] , int size ){ //-->for the option of geting similar words
    char * tmp = (char *) malloc (Max_Line_Length * sizeof(char));
    char * s = (char *) malloc (Max_Word_Length * sizeof(char));
    char ss ;
    int plus = 0;
    char option ;
    for(int t = 0 ; t < 256;t++){
        if(str[0][t] != ' ' ){
            s[plus] = str[0][t];
            plus = plus + 1;
        }else {
            option = str[0][t+1];
            break;
        }   
    }
    int savesReturn ;
    int j = 0;
    for(int i = 2 ;i < size;i++){
        savesReturn = 0;
        tmp = (char *) malloc (Max_Line_Length * sizeof(char));
        strcpy(tmp , "");
        while(j < Max_Line_Length && str[i][j] != '\n'){
            ss = str[i][j];
            strncat(tmp , &ss , 1);
            j++;
        }
        j=0;
        int lengthOfRaw = strlen(tmp);
        char * word = (char *) malloc (Max_Word_Length * sizeof(char));
        int starterIndex = 0;
        if(option == 'b'){
            for(int k = 0;k<lengthOfRaw+1 ;k++){
                if(tmp[k] != ' ' && tmp[k] != '\0' && tmp[k] != '\t') {
                    word[starterIndex] = tmp[k];
                    starterIndex = starterIndex+1;
                }else {
                    starterIndex = 0;     
                }
                if(tmp[k] == ' ' || tmp[k] == '\0' ||  tmp[k] == '\t'){
                    checkTheWord(word , s);
                    free(word);
                    word = (char *) malloc (Max_Word_Length * sizeof(char));   
                }    
            }
        }else{
            for(int k = 0;k<lengthOfRaw+1 ;k++){
                if(tmp[k] != ' ' && tmp[k] != '\0' && tmp[k] != '\t') {
                    word[starterIndex] = tmp[k];
                    starterIndex = starterIndex+1;
                }else {
                    starterIndex = 0;     
                }
                if(tmp[k] == ' ' || tmp[k] == '\0' ||  tmp[k] == '\t'){
                    int flagCheck = checkTheLine(word , s);
                    if(flagCheck == 1) savesReturn = 1;
                    free(word);
                    word = (char *) malloc (Max_Word_Length * sizeof(char));   
                }   
            }
            if(savesReturn == 1) printf("%s\n", tmp);
            free(tmp); 
        }
    }
} 


int main(){

    char txt[Max_Lines][Max_Line_Length];
    int size =initStringToSearch(txt);
    printSimilar(txt , size );
    
    return 0;
}