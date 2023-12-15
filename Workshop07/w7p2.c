/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P2)

						  DISCLAIMER

This Work is only for educational purpose, any student who comes across this 
work is not permitted to copy this work. AGAIN Any student who comes across these 
documents is warned NOT TO USE these as their homework as it is plagiarism and 
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_PATH 70
#define MIN_PATH 10
#define ROW 5

struct PlayerInfo
{
    char character;
    int lives;
    int treasures;
    int pastPositions[MAX_PATH];
};

struct GameInfo
{
    int moves;
    int pathLength;
    int bombPosition[MAX_PATH];
    int treasurePosition[MAX_PATH];
};

int main(void)
{
    struct PlayerInfo player1;
    struct GameInfo game;
    int movedPosition;
    int gameOver = 0;
    int i, j, count;
    count = 0;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\nPLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player1.character);
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player1.lives);
        if (player1.lives < MIN_LIVES || player1.lives > MAX_LIVES)
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
    } while (player1.lives < MIN_LIVES || player1.lives > MAX_LIVES);
    printf("Player configuration set-up is complete\n");

    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", ROW, MIN_PATH, MAX_PATH);
        scanf("%d", &game.pathLength);
        if (game.pathLength < MIN_PATH || game.pathLength > MAX_PATH || (game.pathLength % ROW != 0))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", ROW, MIN_PATH, MAX_PATH);
        }
    } while (game.pathLength < MIN_PATH || game.pathLength > MAX_PATH || (game.pathLength % ROW != 0));
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        if ((game.moves > (int)(0.75 * game.pathLength)) || (game.moves < player1.lives))
        {
            printf("    Value must be between %d and %d\n", player1.lives, (int)(0.75 * game.pathLength));
        }
    } while ((game.moves > (int)(0.75 * game.pathLength)) || (game.moves < player1.lives));
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", ROW);
    printf("of %d=BOMB, and %d=NO BOMB. Space-delimit your input.\n", 1, 0);
    printf("(Example: %d %d %d %d %d) NOTE: there are %d to set!\n", 1, 0, 0, 1, 1, game.pathLength);
    for (i = 0; i < (game.pathLength / ROW); i++)
    {
        printf("   Positions [%2d-%2d]: ", count + 1, count + ROW);
        for (j = i; j < (i + ROW); j++)
        {
            scanf("%d", &game.bombPosition[count]);
            count++;
        }
    }
    count=0;
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", ROW);
    printf("of %d=TREASURE, and %d=NO TREASURE. Space-delimit your input.\n", 1, 0);
    printf("(Example: %d %d %d %d %d) NOTE: there are %d to set!\n", 1, 0, 0, 1, 1, game.pathLength);
    for (i = 0; i < (game.pathLength / ROW); i++)
    {
        printf("   Positions [%2d-%2d]: ", count + 1, count + ROW);
        for (j = i; j < (i + ROW); j++)
        {
            scanf("%d", &game.treasurePosition[count]);
            count++;
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:");
    printf("\n   Symbol     : %c\n", player1.character);
    printf("   Lives      : %d\n", player1.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombPosition[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasurePosition[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    for (i = 0; i < game.pathLength; i++)
    {
        player1.pastPositions[i] = 0;
    }
    movedPosition = 0;
    do
    {
        if (movedPosition)
        {
            printf("  ");
            for (i = 0; i < movedPosition - 1; i++)
            {
                printf(" ");
            }
            printf("%c\n", player1.character);
        }
        else
        {
            printf("\n");
        }
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if (player1.pastPositions[i] == 1)
            {
                if (game.bombPosition[i] == 1 && game.treasurePosition[i] == 1)
                {
                    printf("&");
                }
                else if (game.bombPosition[i] == 1)
                {
                    printf("!");
                }
                else if (game.treasurePosition[i] == 1)
                {
                    printf("$");
                }
                else
                {
                    printf(".");
                }
            }
            else
            {
                printf("-");
            }
        }
        printf("\n  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10 == 0)
            {
                printf("%d", (i + 1) / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n  ");
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%d", (i + 1) % 10);
        }
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player1.lives, player1.treasures, game.moves);
        printf("+---------------------------------------------------+\n");
        if (player1.lives <= 0 || game.moves <= 0)
        {
            gameOver = 1;
        }
        else
        {
            do
            {
                printf("Next Move [%d-%d]: ", 1, game.pathLength);
                scanf("%d", &movedPosition);
                if (movedPosition < 1 || movedPosition > game.pathLength)
                {
                    printf("  Out of Range!!!\n");
                }
            } while (movedPosition < 1 || movedPosition > game.pathLength);
            printf("\n");
            if (player1.pastPositions[movedPosition - 1] == 1)
            {
                printf("===============> Dope! You've been here before!\n\n");
            }
            else
            {
                game.moves--;
                player1.pastPositions[movedPosition - 1] = 1;
                if (game.bombPosition[movedPosition - 1] == 1 && game.treasurePosition[movedPosition - 1] == 1)
                {
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                    player1.treasures++;
                    player1.lives--;
                }
                else if (game.bombPosition[movedPosition - 1] == 1)
                {
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                    player1.lives--;
                }
                else if (game.treasurePosition[movedPosition - 1] == 1)
                {
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                    player1.treasures++;
                }
                else
                {
                    printf("===============> [.] ...Nothing found here... [.]\n");
                }
                if (player1.lives <= 0)
                {
                    printf("\nNo more LIVES remaining!\n");
                }
                if (game.moves <= 0)
                {
                    printf("\nNo more MOVES remaining!\n");
                }
                printf("\n");
            }
        }
    } while (gameOver == 0);
    printf("\n##################\n#   Game over!   #\n##################\n");
    printf("\nYou should play again and try to beat your score!\n");
    return 0;
}