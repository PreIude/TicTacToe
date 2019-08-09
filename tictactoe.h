
/***
* Name: Jing Xuan Long
* ID: 1022621
* Email: jlong04@uoguelph.ca
* Date: January 28, 2018
* Course: CIS2500
*
* Description:
***/

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***
* Function prototypes
***/

unsigned short b3tous( char b3[10] );

void b3fromus( char b3[10], unsigned short us );

void boardtob3( char b3[10], char board[60] );

void boardfromb3( char board[60], char b3[10] );

char winner( unsigned short us );

unsigned short next ( unsigned short us, char pos );

int get_move( char b3[10] );

char get_turn( char b3[10] );

unsigned short futureCheck ( unsigned short us, int pos );



struct strategy_struct
{
    char best_move;
    char winner;
};

#endif
