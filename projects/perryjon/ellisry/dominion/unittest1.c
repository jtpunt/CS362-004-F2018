// whoseTurn
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittestHelper.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define TESTS 3
int main(int argc, char** argv)	{
	struct gameState A, B, C;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	printf("Testing whoseTurn Function\n");
	initializeGame(2, k, 4, &A);
	initializeGame(2, k, 4, &B);
	initializeGame(2, k, 4, &C);
	// tests 1-3 see if the program can properly keep track of whose turn it currently is in the game
	bool results[TESTS] = {assertTrue("whoseTurn - A", A.whoseTurn, whoseTurn(&A)), assertTrue("whoseTurn - B", B.whoseTurn, whoseTurn(&B)), assertTrue("whoseTurn - C", C.whoseTurn, whoseTurn(&C))};
	printFinalResult(results, TESTS);
	return 0;
}

