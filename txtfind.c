#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This program get from the user: str (word), id function(a/b) and text.
// for func a - print every line that the str is appear
// for func b - print every similar word to str. 


// consts:
#define LINE 256
#define WORD 30

// get one line from user:
int get_line(char s[]){
    char* temp = s;
    int counter = 0;
    char c = getc(stdin);
    
    while (c!='\n' && !feof(stdin)){
        temp[counter] = c;
        counter++;
        c = getc(stdin);
    }
    return counter;
}

// get one word from user:
int getword(char w[]){
    int counter = 0;
    char* temp = w; 
    char c = fgetc(stdin);
    
    while (c =='\n' || c =='\t' || c =='\r' || c ==' '){
        c = fgetc(stdin);
    }
    // while not end of word:
    while (c!='\n' && c!='\t' && c!='\r' && c!=' ' && c!='\0' && !feof(stdin)){
        temp[counter] = c;
        counter++;
        c = fgetc(stdin);
    }

    return counter;
}

// check if str2 is substring of str1:
int substring(char* str1,char* str2){
    char *ret;
    
    ret = strstr(str1, str2);
    if (ret)
        return 1;
    else
        return 0;
    
}

// return 1 if sting s "equel" to string t otherwise return 0:
int similar(char *s,char *t,int n){
    char* str1C = s;
    char* str2C = t;
    int counter = 0;

    while (*str1C!='\0' || *str2C!='\0'){  
        if (*str1C!='\0' && *str2C!='\0' && *str1C == *str2C){
            str1C++;
            str2C++;
        }
        else if(*str1C!='\0'){
            str1C++;
            counter++;
        }
        else{
            str2C++;
            counter++;
        }
    }
    // if they are similar
    if (counter == n){
        return 1;
    }
    return 0;
}

// get from user line and print it if str is a substring:
void print_lines(char* str){
    // memory menegment:
    char* s;
    s = (char*)calloc(LINE,sizeof(char));
    if (s == NULL){
        return;
    }
    bzero(s,sizeof(char)*LINE);
    
    int count = get_line(s);
    while (count>0 || !feof(stdin)){
        if (substring(s,str) == 1){
            printf("%s\n",s);
        } 
        bzero(s,sizeof(char)*LINE);
        count = get_line(s);
    }
    free(s);
}

// get from user word and print it if it similar to str:
void print_similar_words(char *str){
    // memory menegment:
    char *w;
    w = (char*)calloc(WORD,sizeof(char));
    if (w == NULL){
        return;
    }

    int count = getword(w);
    while (count > 0){
        if (similar(w,str,0) || similar(w,str,1)){
            printf("%s\n", w);
        }
        bzero(w, sizeof(char)*WORD);
        count = getword(w);
    }
    free(w);
}


// running the program for all cases:
int main(void){
    // memory menegment:
    char* firstline = (char*)calloc(LINE,sizeof(char));
    if (firstline == NULL){
        return 1;
    }
    char* str = (char*)calloc(WORD,sizeof(char));
    if (str == NULL){
        return 1;
    }
    // gets first line from standard input:
    fgets(firstline,LINE*sizeof(char),stdin);
    char func;
    bzero(&func,sizeof(char));
    int counter = 0;
    
    // save the input in str(the string) and in func(the operation):
    while (firstline[counter]!=' '){
        str[counter] = firstline[counter];
        counter++;
    }

    while (firstline[counter]!='\n'){
        func = firstline[counter];
        counter++;
    }

    // skip the next line because the second line is empty.
    get_line(NULL);     
 
    // calling the right function based on the user decision:
    if (func == 'a'){
        print_lines(str);
    }
    if (func == 'b'){
        print_similar_words(str);
    }
    free(firstline);
    free(str);
    
    return 0;
}



