#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_OF_ARGS 3
#define ASCII_NUM 48
#define SPACE 32

int getNum(FILE*);
char* getWhiteSpace(FILE*, int*);
void spacing(FILE*, FILE*, int*, char*, int, int timesCalled = 0);
bool isBlock(FILE*, char *, int*);

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

  int lenOfSpace = 0;
  char * whitespace = getWhiteSpace(input, &lenOfSpace);



  fclose(input);
  fclose(output);


  return 0;
}

/* Is used to confirm how many lines there are in the file. */
int getNum(FILE * input){
  char *stringNum = NULL;
  size_t len = 0;
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

void spacing(FILE * input, FILE * output, int * numLines, char* whitespace, int lenOfSpace, int timesCalled){

  int currChar = 0;
  char* currString;
  int* lenOfString;

  while ( currChar = fgetc(input)){
    if (currChar = '.' || currChar == "»"){
      continue;
    }else if (isBlock(input, currString, lenOfString)){
      int lcv =0;
      for(;lcv < *lenOfString; lcv++){
          /*FPUT each Char*/
      }
    }

  }

}

bool isBlock(FILE * input, char * retString, int* lenString){

  int currChar = 0;
  *lenString = 0;

  while (currChar = fgetc(input) != SPACE){
    lenString++;
  }
  for (currChar = 0; currChar < *lenString; currChar++){
    if(){

    }
  }

}
