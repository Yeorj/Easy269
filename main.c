#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define NUM_OF_ARGS 3
#define ASCII_NUM 48
#define SPACE 32

int getNum(FILE*);
char* getWhiteSpace(FILE*, int*);
char* isBlock(FILE*, int*);

int main(int argc, char* argv[]){

  if(argc != NUM_OF_ARGS){
    printf("Please provide an input and output file.\n");
    return EXIT_FAILURE;
  }

  FILE * input = fopen(argv[1], "r");
  FILE * output = fopen(argv[2], "w");

  if(!input || !output){
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  int numLines = getNum(input);
  int lenOfSpace = 0;
  char * whitespace = getWhiteSpace(input, &lenOfSpace);


  fclose(input);
  fclose(output);


  return 0;
}

/* Is used to confirm how many lines there are in the file. */
int getNum(FILE * input){
  char *stringNum = NULL;
  size_t len = 0; // NOT USED, BUT REQUIRED
  int numOfDec = getline(&stringNum, &len, input) - 1; // Minus 1 b/c newline
  int retVal = 0;
  int lcv = 1;

  for (; lcv <= numOfDec; lcv++){
    int addNum = stringNum[numOfDec - lcv] - ASCII_NUM;
    retVal += addNum * pow(10.0, (double)(lcv - 1.0));
  }
  return retVal;
}

char* getWhiteSpace(FILE * input, int* len){
  char* whitespace = NULL;
  size_t req = 0; //Requirement needed, but not used
  *len = getline(&whitespace, &req, input) - 1;

  return whitespace;
}

/* Confirms if is a block and adds spacing */
char* isBlock(FILE* input, int* spacing){
  char* retString = NULL;
  size_t throwaway = 0;
  const char IF[] = "IF";
  const char FOR[] = "FOR";
  const char ENDIF[] = "ENDIF";
  const char NEXT[] = "NEXT";

  getline(&retString, &throwaway, input);

  if(strstr(retString, &IF) || strstr(retString, &FOR)){
    if(strstr(retString, &ENDIF)){
      *spacing -= 1;
    }else{
      *spacing += 1;
    }
  }else if(strstr(retString, &NEXT)){
      *spacing -= 1;
  }
  return retString;
}
