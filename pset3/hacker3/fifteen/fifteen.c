/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(int d);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init(d);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(1000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(int d)
{
    for (int i = 0 ; i < d ; i++)
    {
        for (int j = 0 ; j < d ; j++)
        {
                board[i][j] = d*d - (i * d) - j - 1;
        }
    }
    if (d % 2 == 0)
    {
        int temp =  board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = temp;
    }

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    printf("\n\n");
    for (int i = 0 ; i < d ; i++)
    {
        for (int j = 0 ; j < d ; j++)
        {
            if (board[i][j] == 0)
            {
                printf("    :)   ");
            }
            else if (board[i][j] < 10)
            {
                printf("    %d   ", board[i][j]);
            }
            else
            {
                printf("   %d   ", board[i][j]);
            }
        }
        printf("\n\n\n");
    }
}


/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int temp, i, j, q, w, e, r;
    for (i = 0 ; i < d ; i++)
    {
        for (j = 0 ; j < d ; j++)
        {
            if (board[i][j] == tile)
            {
                q = i;
                w = j;
                break;
            }
        }
    }
    for (i = 0 ; i < d ; i++)
    {
        for (j = 0 ; j < d ; j++)
        {
            if (board[i][j] == 0)
            {
                e = i;
                r = j;
                break;
            }
        }
    }
    if (( q-1 == e && w == r )||( q+1 == e && w == r )||( q == e  && w-1 == r )||( q == e && w+1 == r ))
    {
        for (i = 0 ; i < d ; i++)
        {
            for (j = 0 ; j < d ; j++)
            {
                if (board[i][j] == 0)
                {
                    e = i;
                    r = j;
                    break;
                }
            }
        }
        temp = board[q][w];
        board[q][w] = board[e][r];
        board[e][r] = temp;
        return true;
    }
    return false;
}
/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    return false;
}