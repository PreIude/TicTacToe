//Jing Xuan Long
//jlong04@uoguelph.ca
//Assignment 1 Part 5

#include "tictactoe.h"

int main()
{
  struct strategy_struct recs;
  int userNum=0;      //stores user input number for what move
  char name[20];    //stores user's name
  char temp [5];
  char user;      //stores user piece;
  char cpu;     //stores cpu's piece;
  char board[60];
  char b3[10]="000000000";
  unsigned short us=0;
  unsigned short test;
  boardfromb3(board,b3);
  FILE *fp;
  fp=fopen("strategyfile.bin","rb");    //open file to read mode
  if (!fp)
  {
    printf("Error");
    return 0;
  }
  printf("SHALL WE PLAY A GAME?\n\n");
  printf("PLEASE ENTER YOUR NAME: ");
  fgets(name,20,stdin);     //get user name
  printf("\nGREETINGS %s", name);
  printf("Which side would you like to play (X/O)? ");
  fgets(temp,5,stdin);      //get user piece
  user=temp[0];
  while (user!='x' && user!='o' && user!='X' && user!='O')      //check if user entered a wrong input
  {
    printf("Error, Invalid choice, try again: ");
    fgets(temp,5,stdin);
    user=temp[0];
  }
  if (user=='x' || user=='X')       //assign piece to cpu and user
  {
    printf("Ok, you will be X; I will be O. \n\n");
    cpu='1';
    user='2';
  }
  else
  {
    printf("Ok, you will be O; I will be X. \n\n");
    cpu='2';
    user='1';
  }
  printf("%s\n\n", board);
  while (winner(us)!='1' || winner(us)!='2')       //loop while there is no winner
  {
    if (cpu=='2')       //if cpu is 'X'
    {
      fseek(fp, us*sizeof(recs), SEEK_SET);     //move cursor to proper struct
      fread(&recs, sizeof(recs), 1, fp);      //read info from struct
      printf("My turn; my move is %d\n",(int)recs.best_move);
      us=next(us,recs.best_move);         //apply changes to board
      b3fromus(b3,us);
      boardfromb3(board,b3);
      printf("\n%s\n\n", board);
      if (winner(us)=='2')        //check if won and exits
      {
        printf("I won!\n\nA STRANGE GAME.\nTHE ONLY WINNING MOVE IS\nNOT TO PLAY.\n");
        break;
      }
      if (get_move(b3)==9)        //check if tie and exit
      {
        printf("The game is a tie.\n");
        break;
      }
    }
    if (user=='2')        //if user is 'X'
    {
      do
      {
        printf("Your turn; chose a move [0-8]: ");
        scanf("%d",&userNum);           //get user move input
        test=next(us, (char)userNum);
        if (userNum<0 || userNum>8 || test==0)
        {
          printf("Error, Invalid move\n");
        }
      }
      while(userNum<0 || userNum>8 || test==0);       //loops while input isn't between 0-8 or there is already a piece on the spot that user wants to move to
      us=test;        //apply changes to board
      b3fromus(b3,us);
      boardfromb3(board,b3);
      printf("\n%s\n\n", board);
      if (winner(us)=='2')        //check if user won and exit
      {
        printf("I lost!\n\n");
        break;
      }
      if (get_move(b3)==9)
      {
        printf("The game is a tie.\n");
        break;
      }
    }
    if (cpu=='1')       //if cpu is 'O'
    {
      fseek(fp, us*sizeof(recs), SEEK_SET);
      fread(&recs, sizeof(recs), 1, fp);
      printf("My turn; my move is %d\n",(int)recs.best_move);
      us=next(us,recs.best_move);
      b3fromus(b3,us);
      boardfromb3(board,b3);
      printf("\n%s\n\n", board);
      if (winner(us)=='1')
      {
        printf("I won!\n\nA STRANGE GAME.\nTHE ONLY WINNING MOVE IS\nNOT TO PLAY.\n");
        break;
      }
      if (get_move(b3)==9)
      {
        printf("The game is a tie.\n");
        break;
      }
    }
    if (user=='1')        //if user is 'O'
    {
      do
      {
        printf("Your turn; chose a move [0-8]: ");
        scanf("%d",&userNum);
        test=next(us, (char)userNum);
        if (userNum<0 || userNum>8 || test==0)
        {
          printf("Error, Invalid move\n");
        }
      }
      while(userNum<0 || userNum>8 || test==0);
      us=test;
      b3fromus(b3,us);
      boardfromb3(board,b3);
      printf("\n%s\n\n", board);
      if (winner(us)=='1')
      {
        printf("I lost!\n\n");
        break;
      }
      if (get_move(b3)==9)
      {
        printf("The game is a tie.\n");
        break;
      }
    }
  }
  fclose(fp);
  return 0;
}
