//Jing Xuan Long
//jlong04@uoguelph.ca
//Assignment 1 Part 5

#include "tictactoe.h"

int main(int argc, char** argv)
{
  unsigned short us;
  int i;
  char b3[10];
  char board[60];
  us = (unsigned short)atoi(argv[1]);     //get board in unsigned short form
  printf("Board number: %hu\n",us);
  b3fromus( b3, us );     //convert to base 3 from unsigned short
  printf("Board b3: %s\n", b3);
  boardfromb3(board,b3);      //convert to board from base 3
  printf("Board pic: \n%s\n", board);
  printf("Move: %d\n", get_move(b3));
  printf("Turn: %c\n", get_turn(b3));
  printf("Winner: %c\n", winner(us));
  for (i=0;i<=8;i++)      //loop through each possible move and print consequent board in unsigned short form
  {
    printf("%d -> %hu\n",i+1, next(us,i));
  }
  return 0;
}
