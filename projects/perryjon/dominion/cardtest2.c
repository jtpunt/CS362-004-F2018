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
    int cardsOnHand = numHandCards(&state);
    int numBuys = state.numBuys;
	a = cardEffect(council_room, 0, 0, 0, &state, 1, 0);
	bool results[TESTS] = {assertTrue(cardsOnHand + 5, numHandCards(&state) + 1), assertTrue(numBuys + 1, state.numBuys)}; // should also double check the value of a
	printFinalResult(results, TESTS);
	return 0;
}

