#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Board
{
    int N; //number of queens
    int **matrix;
} Board;

FILE *openFile(const char *, const char *);
void deleteBoard(Board *);
Board *createBoard(FILE *);
void printBoard(Board *, FILE *);
bool isSafe(Board *, int, int);
void printErrorMessage();
bool solveNQ(Board *, int);
