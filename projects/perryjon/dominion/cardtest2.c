  // Council Room
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittestHelper.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define TESTS 2
int main(int argc, char** argv)	{
	struct gameState state;
	int a;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    printf ("Testing council_room card\n");
    initializeGame(2, k, 4, &state);
    int cardsOnHand = numHandCards(&state); // cardsOnHand before calling the card's function - which will increase the # of cards on hand by 5
    int numBuys = state.numBuys; // numBuys before calling the card's function - which will increase by 1 
	a = cardEffect(council_room, 0, 0, 0, &state, 1, 0);
	// test 1 is to see if the player was able to successfully draw 5 cards and remove 1 card from their hand
	// test 2 is to see if the number of buys that the player can make increased by 1
	bool results[TESTS] = {assertTrue(cardsOnHand + 5 - 1, numHandCards(&state)), assertTrue(numBuys + 1, state.numBuys)}; // should also double check the value of a
	printFinalResult(results, TESTS);
	return 0;
}

