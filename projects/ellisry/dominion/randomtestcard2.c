/* 
** Filename: randomTest2.c
** Description: Random test the embargo action card.
** Author: Ryan Ellis
** Class: CS362
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define TESTCARD "embargo"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

// number of random games to run
#define NUM_GAMES 20

// limits on player numbers *Note: MAX_PLAYERS already defined elsewhere
#define MIN_PLAYERS 2

int main(){
    int test1Pass = 0;   // keeps track of how many test 1's passed
    int choice1Flag = 0;   // flag to help check if choice1 random value is valid
    int embargoAmt = 1;    // new embargo amount of whatever card player picks
    int choice1;
    int handpos = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed, numPlayers;    // going to randomize these
    int i;    // counter to keep track of games played
    int j;    // iterator for chcking choice1 randomization
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , embargo, smithy, village, baron, great_hall};

    // setup randomizer
    srand(time(NULL));

    printf("TESTING %s\n\n", TESTCARD);

    // loop to run randomized games
    for (i = 0; i < NUM_GAMES; i++)
    {
        // randomize number of players
        numPlayers = MIN_PLAYERS + rand() % (MAX_PLAYERS+1 - MIN_PLAYERS);
        // randomize seed value for initializing game
        seed = 1 + rand() % (1000+1 - 1);
        // checks to ensure that choice is in the active deck that can be played
        choice1 = 0;
        while(choice1Flag == 0){
            // randomize the player choice to embargo
            choice1 = 0 + rand() % ((treasure_map + 1) - 0);
            // flips the flag if random num for choice is a kingdom card
            for (j = 0; j < 10; ++j)
            {
                if (k[j] == choice1)
                {
                    choice1Flag = 1;
                }
            }
            // also flips if it is 0 - 6 card
            if(choice1 >= 0 && choice1 <= 6){
                choice1Flag = 1;
            }
        }
        // reset flag for next game
        choice1Flag = 0;

        // start reference game used to check test game against
        initializeGame(numPlayers, k, seed, &G);

        // copy reference game to test game
        memcpy(&testG, &G, sizeof(struct gameState));
        // play smithy
        cardEffect(embargo, choice1, choice2, choice3, &testG, handpos, &bonus);

        // Test 1: to ensure supply card the player chooses to embargo does
        if(NOISY_TEST){
            printf("Test 1 - Supply Should be Embargoed\n");
            // analyze choice vs. what is set in the game state
            printf("Player 0's Choice for Supply Card Embargoed: %d\n", choice1);
            printf("'embargoToken' Amount Expected: %d, Actual: %d\n", embargoAmt, testG.embargoTokens[choice1]);
        }
        // increase test counter accordingly
        if(testG.embargoTokens[choice1] == embargoAmt){
            test1Pass++;
        }
    }

    printf("\nTest Summary:\n");
    printf("Test 1 - Player 0's Choice for Supply Card Embargoed - PASS: %d, FAIL: %d\n", test1Pass, (NUM_GAMES - test1Pass));
    
    return 0;
}