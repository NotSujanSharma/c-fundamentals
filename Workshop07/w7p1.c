/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P1)

						  DISCLAIMER

This Work is only for educational purpose, any student who comes across this 
work is not permitted to copy this work. AGAIN Any student who comes across these 
documents is warned NOT TO USE these as their homework as it is plagiarism and 
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PATH 70
#define MIN_PATH 10
#define ROW 5
#define MAX_LIVES 10
#define MIN_LIVES 1
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
    struct PlayerInfo player;
    struct GameInfo game;
    int count = 0, i, j;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.character);
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < MIN_LIVES || player.lives > MAX_LIVES)
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
    } while (player.lives < MIN_LIVES || player.lives > MAX_LIVES);
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
        if ((game.moves > (int)(0.75 * game.pathLength)) || (game.moves < player.lives))
        {
            printf("    Value must be between %d and %d\n", player.lives, (int)(0.75 * game.pathLength));
        }
    } while ((game.moves > (int)(0.75 * game.pathLength)) || (game.moves < player.lives));
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
    count = 0;
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
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.character);
    printf("   Lives      : %d\n", player.lives);
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
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}