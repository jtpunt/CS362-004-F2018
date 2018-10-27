// Smithy
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
    printf ("Testing smithy card\n");
    initializeGame(2, k, 4, &state);
    int cardsOnHand = numHandCards(&state); // cardsOnHand before calling the card's function
	a = cardEffect(smithy, 0, 0, 0, &state, 1, 0);
	// test 1 is to see if the player was able to successfully draw 3 card and remove the smithy card from the player's hand
	// test 2 is to see if the correct value was returned
	bool results[TESTS] = {assertTrue(cardsOnHand + 3 - 1, numHandCards(&state)), assertTrue(a, 0)};
	printFinalResult(results, TESTS);
	return 0;
}

