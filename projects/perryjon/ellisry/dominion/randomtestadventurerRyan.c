/* 
** Filename: randomtestadventurer.c
** Description: Random test the adventurer action card.
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

#define TESTCARD "adventurer"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

// number of random games to run
#define NUM_GAMES 20

// limits on player numbers *Note: MAX_PLAYERS already defined elsewhere
#define MIN_PLAYERS 2

int main(){
    int test1Pass = 0;   // holds how many test cases passed for total
    int refNumTreasure;   // holds num of treasure card in ref game
    int testNumTreasure;   // holds num of treasure card in test game
    int newTreasure = 2;   // should have 2 more treasure cards after play
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed, numPlayers;    // going to randomize these
    int i;    // counter to keep track of games played
    int j;    // counter to get num of treasure cards
    int l;    // counter to go thru players deck
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    int treasure[3] = {copper, silver, gold};

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
        // clear out values for treasure cards
        refNumTreasure = 0;
        testNumTreasure = 0;

        // start reference game used to check test game against
        initializeGame(numPlayers, k, seed, &G);

        // copy reference game to test game
        memcpy(&testG, &G, sizeof(struct gameState));
        // play adventurer
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        // Test 1: to ensure player 0 has two treasure cards at 
        // end of turn
        // get number of treasure cards in reference game
        for (j = 0; j < 3; j++)
        {
            for(l = 0; l < (G.handCount[0] - 1); l++){
                if(G.hand[0][l] == treasure[j]){
                    refNumTreasure++;
                }
            }
        }
        // get number of treasure cards in test game
        for (j = 0; j < 3; j++)
        {
            for(l = 0; l < (testG.handCount[0] - 1); l++){
                if(testG.hand[0][l] == treasure[j]){
                    testNumTreasure++;
                }
            }
        }
        if(NOISY_TEST){
            printf("Test 1 - Treasure Cards Player 0 Has: %d, Expected: %d\n", testNumTreasure, (refNumTreasure + newTreasure));            
        }
        if(refNumTreasure + newTreasure == testNumTreasure){
            test1Pass++;
        }
    }

    printf("\nTest Summary:\n");
    printf("Test 1 Player 0 Has 2 Treasure Cards - PASS: %d, FAIL: %d\n", test1Pass, (NUM_GAMES - test1Pass));
    
    return 0;
}