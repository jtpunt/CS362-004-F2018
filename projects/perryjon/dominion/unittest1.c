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
// whoseTurn
int main(int argc, char** argv)	{
	struct gameState A, B, C;
	int a;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	printf("Testing whoseTurn Function\n");
	initializeGame(2, k, 4, &A);
	initializeGame(2, k, 4, &B);
	initializeGame(2, k, 4, &C);
	bool results[TESTS] = {assertTrue(A.whoseTurn, whoseTurn(&A)), assertTrue(B.whoseTurn, whoseTurn(&B)), assertTrue(C.whoseTurn, whoseTurn(&C))};
	printFinalResult(results, TESTS);
	return 0;
}

