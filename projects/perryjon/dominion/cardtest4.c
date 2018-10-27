// Garden
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
	printf ("Testing Adventurer card\n");
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 4, &state);
	a = cardEffect(gardens, 0, 0, 0, &state, 1, 0);
	bool results[TESTS] = {assertTrue(a, 1), assertTrue(1, state.numActions)};
	printFinalResult(results, TESTS);
	return 0;
}
