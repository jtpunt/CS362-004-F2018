/* 
** Filename: cardTest1.c
** Description: Test the smithy action card.
** Author: Ryan Ellis
** Class: CS362
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

#define TESTCARD "smithy"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main(){
    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    // start reference game used to check test game against
    initializeGame(numPlayers, k, seed, &G);

    printf("TESTING %s\n\n", TESTCARD);

    // Test 1: to ensure the correct amount of cards are moved between
    // hand/deck/discard pile
    printf("Test 1 - Player 0's Deck/Hand/Discard Piles\n");

    // copy reference game to test game
    memcpy(&testG, &G, sizeof(struct gameState));
    // play smithy
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    // smithy results in drawing 3 cards
    newCards = 3;

    // display results
    printf("Hand Count: %d, Expected: %d\n", testG.handCount[thisPlayer], (G.handCount[thisPlayer] + newCards - discarded));

    if(testG.handCount[thisPlayer] == (G.handCount[thisPlayer] + newCards - discarded))
    	printf("PASS: Amount in hand after playing smithy is NET +2.\n\n");
    else
    	printf("FAIL: Amount in hand after playing smithy is NET +2.\n\n");

    printf("Deck Count: %d, Expected: %d\n", testG.deckCount[thisPlayer], (G.deckCount[thisPlayer] - newCards + shuffledCards));

    if(testG.deckCount[thisPlayer] == (G.deckCount[thisPlayer] - newCards + shuffledCards))
    	printf("PASS: Amount in deck after playing smithy is NET -3.\n\n");
    else
    	printf("FAIL: Amount in deck after playing smithy is NET -3.\n\n");

    printf("Discard Count: %d, Expected: %d\n", testG.discardCount[thisPlayer], (G.discardCount[thisPlayer] + discarded));

    if(testG.discardCount[thisPlayer] == (G.discardCount[thisPlayer] + discarded))
    	printf("PASS: Amount in discard pile after playing smithy is NET +1.\n\n");
    else
    	printf("FAIL: Amount in discard pile after playing smithy is NET +1.\n\n");

    return 0;
}