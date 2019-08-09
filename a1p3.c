//Jing Xuan Long
//jlong04@uoguelph.ca
//Assignment 1 Part 3

#include "tictactoe.h"

int main(int argc, char** argv)
{
  int greatest=0;     //flag for the largest move
  int greatestIndex=0;      //stores which position (0-8) the largest move is located
  int j;
  int userChoice;     //stores commandline argument inputted
  int winState;     //flag for if a board has been assigned a best move
  unsigned short futureState;     //stores future board states
  unsigned short i;     //increment counter as ashort for each board

  char b3[10];
  FILE *fp;
  userChoice=atoi(argv[1]);
  fp=fopen("strategyfile.bin","rb+");     //open file in read/write mode
  if (!fp)
  {
    printf("Error");
    return 0;
  }
  for (i=0;i<19683;i++)     //loops through each board
  {
    b3fromus(b3, i);
    winState=0;
    if (userChoice==get_move(b3))     //checks if board matches amount of moves entered by user
    {
      if (winner(i)=='1'|| winner(i)=='2')      //if the board has a winner, assign the proper values and write to binary
      {
        struct strategy_struct recs={(char)-1, winner(i)};
        fseek(fp, sizeof(recs)*i, SEEK_SET);
        fwrite(&recs, sizeof(recs), 1, fp);
        winState=1;     //flag that a move has been written
      }
      else
      {
        for (j=0;j<=8;j++)      //loop through each possible move
        {
             if (next(i,j)!=0 && greatest==0)     //stores largest possible move
             {
               greatest=1;      //flag that it has been found in this board
               greatestIndex=j;     //stores it's index
             }
          if (winner(next(i,j))=='1' || winner(next(i,j)) =='2')      //checks if a move leads to victory and writes to binary
          {
            struct strategy_struct recs={(char)j, winner(next(i,j))};
            fseek(fp, sizeof(recs)*i, SEEK_SET);
            fwrite(&recs, sizeof(recs), 1, fp);
            winState=1;
          }
        }
        greatest=0;     //reset flag
        for (j=0;j<=8;j++)
        {
          futureState=futureCheck(i,j);
          if ((winner(futureState)=='1' || winner(futureState)=='2') && winState==0)   //checks if a move will lead to a tie and if so, block it
          {
            struct strategy_struct recs={(char)j, '0'};
            fseek(fp, sizeof(recs)*i, SEEK_SET);
            fwrite(&recs, sizeof(recs), 1, fp);
            winState=1;
          }
        }
        for (j=0;j<=8;j++)
        {
          if (winner(next(i,j))==' ' && winState==0)      //checks if next move leads to no winner and if true write the largest move as the best move
          {
            if(get_turn(b3)=='1')
            {
              struct strategy_struct recs={(char)greatestIndex, '1'};
              fseek(fp, sizeof(recs)*i, SEEK_SET);
              fwrite(&recs, sizeof(recs), 1, fp);
            } else{
              struct strategy_struct recs={(char)greatestIndex, '2'};
              fseek(fp, sizeof(recs)*i, SEEK_SET);
              fwrite(&recs, sizeof(recs), 1, fp);
            }
            winState=1;
            break;
          }
        }
      }
    }
  }
  fclose(fp);
  return 0;
}
