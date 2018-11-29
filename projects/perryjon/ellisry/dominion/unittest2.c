// isGameOver
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittestHelper.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_COINS 10
#define GOLD_COINS 3
#define SILVER_COINS 2
#define COPPER_COINS 1
#define TESTS 3
int main(int argc, char** argv)	{
	struct gameState A, B, C;
	int i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	printf ("Testing isGameOver Function\n");
	initializeGame(2, k, 4, &A);
	initializeGame(2, k, 4, &B);
	initializeGame(2, k, 4, &C);
	B.supplyCount[province] = 0;
	C.supplyCount[province] = 1;
	for (i = 0; i < 25; i++){
	    if (i != 3){ // skip province in the for loop as we set it to 1 earlier
	    	C.supplyCount[i] = 0;
	    }
  	}
  	// test 1 is to test to see if the game is over - which is true in this test - meaning the game is not over
  	// test 2 is to test to see if the game is over when the stack of Province cards is empty - which is true in this test - meaning the game is over
  	// test 3 is to test to see if all 3 supply piles are at three - which is true in this test - meaning the game is over
	bool results[TESTS] = {assertTrue("isGameOver - A", isGameOver(&A), 0), assertTrue("isGameOver - B", isGameOver(&B), 1), assertTrue("isGameOver - C", isGameOver(&C), 1)};

	printFinalResult(results, TESTS);
	  
	return 0; 
}