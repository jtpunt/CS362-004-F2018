/* 
** Filename: unitTest2.c
** Description: Test the discardCard function.
** Author: Ryan Ellis
** Class: CS362
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

// set NOISE_TEST to 0 remove printfs from output
#define NOISY_TEST 1

int main(){
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    int otherCards[17] = {curse, estate, duchy, province, copper, silver};
    struct gameState G;

    
    printf("TESTING fullDeckCount()\n\n");

    r = initializeGame(numPlayer, k, seed, &G);    // intialize two player game

    printf("Test 1 - Player 1's Deck\n");   // check to ensure correct amount of cards returned when cards added to Player 1's deck
    for(i = 0; i < 5; i++){
    	G.deck[1][i] = k[0]; // add 5 adventurers to deck (we know their hand and discard are empty)
    }
    if((fullDeckCount(1, adventurer, &G)) == 5)
    	printf("PASS: All 5 adventurer cards accounted for by 'fullDeckCount'.\n\n");
    else
    	printf("FAIL: All 5 adventurer cards accounted for by 'fullDeckCount'.\n\n");

    printf("Test 2 - Enter Invalid (High) Card\n"); // range of cards is -1 (empty spot) - 26
    if((fullDeckCount(1, 27, &G)) == 0)
    	printf("PASS: 'fullDeckCount' did not count any invalid cards.\n\n");
    else
    	printf("FAIL: 'fullDeckCount' did not count any invalid cards.\n\n");


return 0;
}

