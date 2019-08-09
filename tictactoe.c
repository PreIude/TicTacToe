#include "tictactoe.h"

unsigned short b3tous( char b3[10] )
{
  unsigned short us=0;
  int i;
  int temp;
  for (i=8;i>=0;i--)        //loop through base3 number from left to right
  {
    if (b3[i]!='0')       //calculate
    {
      temp=b3[i]-48;
      if (i==8)
      {
        us=us+temp*1;
      }
      else if (i==7)
      {
        us=us+temp*3;
      }
      else if (i==6)
      {
        us=us+temp*9;
      }
      else if (i==5)
      {
        us=us+temp*27;
      }
      else if (i==4)
      {
        us=us+temp*81;
      }
      else if (i==3)
      {
        us=us+temp*243;
      }
      else if (i==2)
      {
        us=us+temp*729;
      }
      else if (i==1 )
      {
        us=us+temp*2187;
      }
      else if (i==0)
      {
        us=us+temp*6561;
      }
    }
  }
  return us;
}

void b3fromus( char b3[10], unsigned short us )
{
  int remainder = 0;
  int i;
  b3[9]='\0';
  for (i=8; i>=0;i--)       //loop through base3 number
  {
    remainder= us%3;        //calculate
    b3[i]= '0'+remainder;
    us=us/3;
  }
  return;
}

void boardtob3( char b3[10], char board[60] )
{
  int i=0;
  int j;
  b3[9]='\0';
  for (j=1;j<=9;j=j+4)        //loop through first row from the the bottom
  {
    if (board[j]==' ')        //if index is empty, assign a 0
    {
      b3[i]='0';
      i++;
    }
    else if (board[j]=='O')       //if index is a O, assign a 1
    {
      b3[i]='1';
      i++;
    }
    else if (board[j]=='X')       //if index is a X, assign a 2
    {
      b3[i]='2';
      i++;
    }
    else {
      printf("Error\n");
    }
  }
  for (j=25;j<=33;j=j+4){       //loop through second row and repeat
    if (board[j]==' ')
    {
      b3[i]='0';
      i++;
    }
    else if (board[j]=='O')
    {
      b3[i]='1';
      i++;
    }
    else if (board[j]=='X')
    {
      b3[i]='2';
      i++;
    }
    else
    {
      printf("Error\n");
    }
  }
  for (j=49;j<=57;j=j+4)        //loop through third row and repeat
  {
    if (board[j]==' ')
    {
      b3[i]='0';
      i++;
    }
    else if (board[j]=='O')
    {
      b3[i]='1';
      i++;
    }
    else if (board[j]=='X')
    {
      b3[i]='2';
      i++;
    }
    else
    {
      printf("Error\n");
    }
  }
}

void boardfromb3( char board[60], char b3[10] )
{
  int i=0;
  int j;
  strcpy(board,"   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0");       //create an empty board
  for (j=1;j<=9;j=j+4)      //loop through first row from the bottom
  {
    if (b3[i]=='1')       //if index is 1, assign an O
    {
      board[j]='O';
    }
    else if (b3[i]=='2')    //if index is 2, assign an X
    {
      board[j]='X';
    }
    else if (b3[i]!='0')    //if index is something other than a 0, return an error
    {
      printf("Error\n");
      return;
    }
    i++;    //increment move counter
  }
  for (j=25;j<=33;j=j+4)    //loop through second row and repeat
  {
    if (b3[i]=='1')
    {
      board[j]='O';
    }
    else if (b3[i]=='2')
    {
      board[j]='X';
    }
    else if (b3[i]!='0')
    {
      printf("Error\n");
      return;
    }
    i++;
  }
  for (j=49;j<=57;j=j+4)    //loop through third row and repeat
  {
    if (b3[i]=='1'){
      board[j]='O';
    }
    else if (b3[i]=='2')
    {
      board[j]='X';
    }
    else if (b3[i]!='0')
    {
      printf("Error\n");
      return;
    }
    i++;
  }
}

char winner( unsigned short us )
{
  char b3[10];
  b3fromus(b3,us);
  if ((b3[0]=='1' && b3[1] == '1' && b3[2] == '1') || (b3[3]=='1' && b3[4] == '1' && b3[5] == '1') || (b3[6]=='1' && b3[7]
  == '1' && b3[8] == '1') || (b3[0]=='1' && b3[3] == '1' && b3[6] == '1') || (b3[1]=='1' && b3[4] == '1' && b3[7] == '1') ||
  (b3[2]=='1' && b3[5] == '1' && b3[8] == '1') || (b3[0]=='1' && b3[4] == '1' && b3[8] == '1') || (b3[2]=='1' && b3[4] == '1' &&
  b3[6] == '1'))        //checks winning board combinations for O
  {
    return '1';
  }
  else if ((b3[0]=='2' && b3[1] == '2' && b3[2] == '2') || (b3[3]=='2' && b3[4] == '2' && b3[5] == '2') || (b3[6]=='2' && b3[7]
  == '2' && b3[8] == '2') || (b3[0]=='2' && b3[3] == '2' && b3[6] == '2') || (b3[1]=='2' && b3[4] == '2' && b3[7] == '2') ||
  (b3[2]=='2' && b3[5] == '2' && b3[8] == '2') || (b3[0]=='2' && b3[4] == '2' && b3[8] == '2') || (b3[2]=='2' && b3[4] == '2' &&
  b3[6] == '2'))      //checks winning board combinations for X
  {
    return '2';
  }
  else if (get_move(b3)==9)       //if there has been 9 moves without passing previous checks then it is a tie
  {
    return '0';
  }
  else        //else the board state is incomplete
  {
    return ' ';
  }
}

unsigned short next ( unsigned short us, char pos )
{
  char b3[10];
  b3fromus(b3, us);
  char turn[2]= " \0" ;
  turn[0]=get_turn(b3);
  int position = (int)pos;
  if (b3[position]=='0')      //check if position on board is empty
  {
    if (turn[0]=='1')     //checks if it's O's turn and puts piece onto board
    {
      b3[position]='1';
    }
    else  //else it's X's turn and puts piece onto board
    {
      b3[position]='2';
    }
  }
  else if (b3[position]=='1'|| b3[position]== '2')    //check if position on board isn't empty then return 0;
  {
    return 0;
  }
  return b3tous(b3);    //return board with updated values post move
}

int get_move( char b3[10] )
{
  int i;
  int count=0;
  for (i=0;i<=8;i++){     //loops through each index on board 
    if (b3[i]=='1' || b3[i]=='2'){    //checks if there are 1s and 2s and increments by 1 each time
      count++;
    }
  }
  return count;   //returns number of turns
}

char get_turn( char b3[10] )
{
  int turn = get_move(b3);
  if (turn%2==0){     //if turn count is even, then it's X's turn
    return '2';
  }
  else{   //else it's odd, then it's O's turn
    return '1';
  }
}

unsigned short futureCheck ( unsigned short us, int pos )
{
  char b3[10];
  b3fromus(b3, us);
  char turn;
  turn=get_turn(b3);
  if (b3[pos]=='0'){    //check if position on board is empty
    if (turn=='1'){   //check turn then look at the possibilities for the opposite player
      b3[pos]='2';
    } else {
      b3[pos]='1';
    }
  }
  else if (b3[pos]=='1'|| b3[pos]== '2')
  {
    return 0;
  }
  return b3tous(b3);
}
