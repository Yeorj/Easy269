#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_OF_ARGS 3
#define ASCII_NUM 48

int getNum(FILE*);

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

  printf("The number in the file is %d\n", getNum(input));


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
