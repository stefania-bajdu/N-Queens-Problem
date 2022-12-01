#include <board.h>

bool isSafe(Board *src, int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++) // check left side
        if (src->matrix[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) // upper diagonal on left side
        if (src->matrix[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < src->N; i++, j--) // lower diagonal on left side
        if (src->matrix[i][j])
            return false;

    return true;
}

bool solveNQ(Board *src, int col)
{
    int i;
    if (col >= src->N) // if all queens are placed
        return true;
    /* Consider this column and try placing this queen in all rows one by one,
    it is not necessary to check the right sides of diagonals or lines due to the
    starting point and direction of movement in placing the current queen */
    for (i = 0; i < src->N; i++)
        if (isSafe(src, i, col))
        {
            src->matrix[i][col] = 1;
            if (solveNQ(src, col + 1))
                return true;
            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            src->matrix[i][col] = 0;
        }

    return false;
}

Board *createBoard(FILE *input)
{
    Board *src = (Board *)malloc(sizeof(Board));
    int i;
    fscanf(input, "%d", &src->N);
    src->matrix = (int **)malloc(src->N * sizeof(int *));
    if (src->matrix)
        for (i = 0; i < src->N; i++)
            src->matrix[i] = (int *)calloc(src->N, sizeof(int));
    else
        printErrorMessage();
    return src;
}

void printErrorMessage()
{
    printf("ERROR while allocating memory.\n");
    exit(1);
}

void printBoard(Board *src, FILE *output)
{
    int i, j;
    for (i = 0; i < src->N; i++)
    {
        for (j = 0; j < src->N; j++)
            fprintf(output, "%2d\t", src->matrix[i][j]);
        fprintf(output, "\n");
    }
}

void deleteBoard(Board *src)
{
    int i;
    for (i = 0; i < src->N; i++)
        free(src->matrix[i]);
    free(src->matrix);
    free(src);
    src = NULL;
}

FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (!file)
    {
        printf("ERROR while opening %s file!\n", filename);
        exit(1);
    }
    return file;
}