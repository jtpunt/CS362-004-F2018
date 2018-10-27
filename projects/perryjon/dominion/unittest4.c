// updateCoins
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
	struct gameState copperState, silverState, goldState;
	int i;
	
	printf ("Testing updateCoins Function\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 4, &copperState);
    initializeGame(2, k, 4, &silverState);
    initializeGame(2, k, 4, &goldState); // somehow has 5 more coins than silverState
    for(i = 0; i < MAX_COINS; i++){
    	copperState.hand[0][i] = copper; // fill each hand with treasure cards
    	silverState.hand[0][i] = silver;
    	goldState.hand[0][i] = gold;
    }
	copperState.handCount[0] = MAX_COINS; // update handCount to reflect the correct # of treasure cards on hand
	silverState.handCount[0] = MAX_COINS;
	goldState.handCount[0] = MAX_COINS;
    updateCoins(0, &copperState, 0);
    updateCoins(0, &silverState, 0);
    updateCoins(0, &goldState, 0);
    // test 1 compares the # of coins that should be calculated by updateCoins for copper cards to secondary manual calculation of how many coins this should be
    // test 2 - 3 do the same as above, but for silver and gold cards
    bool results[TESTS] = {assertTrue(copperState.coins, MAX_COINS * COPPER_COINS), assertTrue(silverState.coins, MAX_COINS * SILVER_COINS), assertTrue(goldState.coins, MAX_COINS * GOLD_COINS)};
    printFinalResult(results, TESTS);

	return 0;
}