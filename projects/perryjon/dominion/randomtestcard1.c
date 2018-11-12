#include "dominion.h"
#include "dominion_helpers.h"
#include "unittestHelper.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define TESTS 3
int main(int argc, char** argv) {
    srand(time(NULL));
    struct gameState stateA, stateB;
    int currPlayer, numPlayers;
    int a, i, j, seed = (rand() % 1000) + 1000;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    printf ("Testing Council card\n");
    bool results[TESTS * 2];
    int count = 0;
    for(i = 0; i < TESTS; i++){
        initializeGame(2, k, 4, &stateA);
        stateA.handCount[stateA.whoseTurn] = rand() % MAX_HAND;
        stateA.numActions = rand() % 7;
        stateA.numBuys = rand() % 7;
        int cardsOnHand = numHandCards(&stateA); // cardsOnHand before calling the card's function - which will increase the # of cards on hand by 5
        int numBuys = stateA.numBuys; // numBuys before calling the card's function - which will increase by 1 

        // memcpy(&stateB, &stateA, sizeof(struct gameState));
        a = cardEffect(council_room, 0, 0, 0, &stateA, 1, 0);

        results[count++] = assertTrue("cardsOnHand", cardsOnHand + 5 - 1, numHandCards(&stateA));
        results[count++] = assertTrue("numBuys", numBuys + 1, stateA.numBuys);
    }
    printFinalResult(results, TESTS);
    return 0;
}
