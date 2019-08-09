//Jing Xuan Long
//jlong04@uoguelph.ca
//Assignment 1 Part 2

#include "tictactoe.h"

int main()
{
  int i;
  FILE *fp;
  struct strategy_struct recs={(char)-1, ' '};      //initialize struct to write into binary file
  fp = fopen("strategyfile.bin","wb");      //open file in write mode
  if (!fp)
  {
    printf("Error");
    return 0;
  }
  for (i=0;i<19683;i++)     //loop through 19683 times and write the struct into a binary file
  {
    fwrite(&recs, sizeof(recs), 1, fp);
  }
  fclose(fp);
  return 0;
}
