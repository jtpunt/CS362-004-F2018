/* 
** Filename: unitTest1.c
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
	int seed = 1000;
	int numPlayer = 2;
	int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int discardedCard;
    int player0HandCount;

    printf("TESTING discardCard():\n\n");

    r = initializeGame(numPlayer, k, seed, &G);    // initialize the test game

    printf("Test 1 - Trash Flag\n");    // when trash flag (-1) is passed as argument
    discardedCard = G.hand[0][0];
    discardCard(0, 0, &G, -1);
    if(G.playedCards[0] == discardedCard)
        printf("PASS: Player trashes card. That card in 'playedCard' pile.\n\n");
    else
        printf("FAIL: Player trashes card. That card in 'playedCard' pile.\n\n");

    r = initializeGame(numPlayer, k, seed, &G);    // re-initialize test game

    printf("Test 2 - No Trash Flag\n");    // when trash flag not set
    G.whoseTurn = 0;    // update game state, so player 0's turn
    discardedCard = G.hand[0][0];    // record what card to be discarded
    printf("Discarded Card: %d.\n", discardedCard);
    discardCard(0, 0, &G, 1);
    printf("Card in 'discardCard' Pile: %d.\n", G.discard[0][0]);
    if(G.discard[0][0] == discardedCard)
        printf("PASS: Player discards card. That card in that player's 'discardCard' pile.\n\n");
    else
        printf("FAIL: Player discards card. That card in that player's 'discardCard' pile.\n\n");

    r = initializeGame(numPlayer, k, seed, &G);    // re-initialize test game

    printf("Test 3 - Player 0's Hand Count\n");    // checks players hand count after discarding
    player0HandCount = G.handCount[0];
    printf("Player 0 hand count before discard: %d.\n", G.handCount[0]);
    discardCard(0, 0, &G, 1);
    printf("Player 0 hand count after discard: %d.\n", G.handCount[0]);
   if(G.handCount[0] < player0HandCount)
        printf("PASS: Player 0 has less cards after 'discardCard'\n\n");
    else
        printf("FAIL: Player 0 has less cards after 'discardCard'\n\n");


    return 0;
}
