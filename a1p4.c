//Jing Xuan Long
//jlong04@uoguelph.ca
//Assignment 1 Part 4

#include "tictactoe.h"

int main(int argc, char** argv)
{
  int i;
  int offset;       //stores board number
  struct strategy_struct recs;        //initialize struct
  unsigned short us;
  char b3[10];
  char board[60];
  us = (unsigned short)atoi(argv[1]);
  offset=atoi(argv[1]);       //convert command line argument into an integer
  FILE *fp;
  fp=fopen("strategyfile.bin","rb");        //open file in read mode
  if (!fp)
  {
    printf("Error");
    return 0;
  }
  fseek(fp, offset*sizeof(recs), SEEK_SET);       //move cursor to designated struct
  fread(&recs, sizeof(recs), 1, fp);        //read in struct
  fclose(fp);
  printf("Board number: %hu\n",us);       //print board info
  b3fromus( b3, us );
  printf("Board b3: %s\n", b3);
  boardfromb3(board,b3);
  printf("Board pic: \n%s\n", board);
  printf("Move: %d\n", get_move(b3));
  printf("Turn: %c\n", get_turn(b3));
  printf("Winner: %c\n", winner(us));
  printf("best move=%d, winner=%c\n", (int)recs.best_move, recs.winner);
  for (i=0;i<=8;i++)        //displays all possible moves that can be taken
  {
    printf("%d -> %hu\n",i, next(us,i));
  }
  return 0;
}
