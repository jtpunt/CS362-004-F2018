/* 
** Filename: randomTest1.c
** Description: Random test the smithy action card.
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

#define TESTCARD "smithy"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

// number of random games to run
#define NUM_GAMES 20

// limits on player numbers *Note: MAX_PLAYERS already defined elsewhere
#define MIN_PLAYERS 2

int main(){
    int test1Pass = 0;   // keeps track of how many test 1's passed
    int newToHand = 3;   // should have 2 more treasure cards after play
    int newToDiscard = 1;    // should have 1 more card in discard pile
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed, numPlayers;    // going to randomize these
    int i;    // counter to keep track of games played
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

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

        // start reference game used to check test game against
        initializeGame(numPlayers, k, seed, &G);

        // copy reference game to test game
        memcpy(&testG, &G, sizeof(struct gameState));
        // play smithy
        cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

        // Test 1: to ensure player 0 has three more cards in hand
        if(NOISY_TEST){
            printf("Test 1 - Player 0's Has 2 More Cards In Hand\n");
            // analyze num of cards in test game hand vs. expected
            printf("Num Cards In Player 0's Hand: %d, Expected: %d\n", testG.handCount[0], (G.handCount[0] + newToHand));
        }
        // increase test counter accordingly
        if(testG.handCount[0] == (G.handCount[0] + newToHand)){
            test1Pass++;
        }
    }

    printf("\nTest Summary:\n");
    printf("Test 1 - Player 0's Has 2 More Cards In Hand - PASS: %d, FAIL: %d\n", test1Pass, (NUM_GAMES - test1Pass));
    
    return 0;
}