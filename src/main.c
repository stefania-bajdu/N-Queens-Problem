#include <board.h>

int main(int argc, char **argv)
{
    Board *src;
    FILE *input, *output;
    input = openFile(argv[1], "rt");
    output = openFile(argv[2], "wt");
    src = createBoard(input);
    fclose(input);
    if (!solveNQ(src, 0))
        fprintf(output, "Solution does not exist!\n");
    else
        printBoard(src, output);
    fclose(output);
    deleteBoard(src);
    return 0;
}
