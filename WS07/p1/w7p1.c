/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Nathan Kong
Student ID#: 150950236
Email      : nkong@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#define MIN_NUM_LIVES 1
#define MAX_NUM_LIVES 10

#define MIN_PATH_LEN 10
#define MAX_PATH_LEN 70
#define PATH_LEN_MUL 5
#define MAX_PATH_PER 0.75

#include <stdio.h>

struct PlayerInfo {
    int numLives;
    char charSymb;
    int numTreas;
    int moves[MAX_PATH_LEN];
};

struct GameInfo {
    int maxNumMoves;
    int pathLen;
    int bombs[MAX_PATH_LEN];
    int treas[MAX_PATH_LEN];
};


int main(void) {
    int repeat = 1;
    int i = 0, j = 0;
    int minMoves, maxMoves;

    struct PlayerInfo player;
    struct GameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    // Configure player
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.charSymb);

    // Validate numLives
    do {
        printf("Set the number of lives: ");
        scanf(" %d", &player.numLives);

        if (player.numLives < MIN_NUM_LIVES || player.numLives > MAX_NUM_LIVES) {
            repeat = 1;
            printf("     Must be between %d and %d!\n", MIN_NUM_LIVES, MAX_NUM_LIVES);
        } else {
            repeat = 0;
        }
    } while (repeat);

    for (i = 0; i < MAX_PATH_LEN; ++i) {
        player.moves[i] = 0;
    }

    printf("Player configuration set-up is complete\n\n");

    // Configure the game
    printf("GAME Configuration\n");
    printf("------------------\n");

    // Validate pathLen
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", PATH_LEN_MUL, MIN_PATH_LEN, MAX_PATH_LEN);
        scanf(" %d", &game.pathLen);

        if (game.pathLen % PATH_LEN_MUL || game.pathLen < MIN_PATH_LEN || game.pathLen > MAX_PATH_LEN) {
            repeat = 1;
            printf("     Must be a multiple of %d and between %d-%d!!!\n", PATH_LEN_MUL, MIN_PATH_LEN, MAX_PATH_LEN);
        } else {
            repeat = 0;
        }
     } while (repeat);

    // Validate maxNumMoves
    minMoves = player.numLives;
    maxMoves = game.pathLen * MAX_PATH_PER;
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf(" %d", &game.maxNumMoves);

        if (game.maxNumMoves < minMoves || game.maxNumMoves > maxMoves) {
            repeat = 1;
            printf("    Value must be between %d and %d\n", minMoves, maxMoves);
        } else {
            repeat = 0;
        }
    } while (repeat);

    // Configure bombs placements
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", PATH_LEN_MUL);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLen);

    for (i = 0; i < game.pathLen; i += PATH_LEN_MUL) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + PATH_LEN_MUL);

        for (j = 0; j < PATH_LEN_MUL; ++j) {
            scanf("%d", &game.bombs[i + j]);
        }
    }
    printf("BOMB placement set\n");

    // Configure treas placements
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", PATH_LEN_MUL);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLen);

    for (i = 0; i < game.pathLen; i += PATH_LEN_MUL) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + PATH_LEN_MUL);

        for (j = 0; j < PATH_LEN_MUL; ++j) {
            scanf("%d", &game.treas[i + j]);
        }
    }
    printf("TREASURE placement set\n");

    // Display summary
    printf("\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.charSymb);
    printf("   Lives      : %d\n", player.numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLen);
    
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLen; ++i) {
        printf("%d", game.bombs[i]);
    }
    printf("\n");

    printf("   Treasure   : ");
    for (i = 0; i < game.pathLen; ++i) {
        printf("%d", game.treas[i]);
    }
    printf("\n");

    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    printf("\n");

    return 0;
}
