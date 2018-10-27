// buyCard
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
#define TESTS 4
int main(int argc, char** argv)	{
	struct gameState G;
	printf("Testing buyCard Function");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 4, &G);
	G.supplyCount[estate] = 2;
	G.numBuys = 1; 
	G.coins = 2;
	// if numBuys is < 1, you don't have any buys left - return -1
	// else if there is no supply left of that card, then you can't buy it - return -1
	// else if the # of coins that you have is < cost to buy the item, then you can't buy it - return -1
	// OTHERWISE, you can buy the card
	// phase=1
	// # of coins that the player has is decreased
	// # of buys that the player can do decreases by 1
	// return 0 - no errors
	// 1st test is to see if we can successfully buy an estate card for 2 coins - which should be true as we have started with 2 coins
	// 2nd test is to see if we can successfully not buy when there's no supply left
	// 3rd test is to see if we can successfully not buy when the player has no buys left
	// 4th test is to see if the gameState variable 'phase' is equal to 1
	bool results[TESTS] = {assertTrue(buyCard(1, &G), 0), assertTrue(buyCard(1, &G), -1), assertTrue(buyCard(1, &G), -1), assertTrue(G.phase, 1)};

	printFinalResult(results, TESTS);
	
	return 0; 
}