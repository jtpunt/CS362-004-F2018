// Adventurer
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
    printf ("Testing Adventurer card\n");
    bool results[TESTS * 5];
    int count = 0;
    for(i = 0; i < TESTS; i++){
        initializeGame(2, k, 4, &stateA);

        stateA.numActions = rand() % 7;
        stateA.numBuys = rand() % 7;
        stateA.coins = rand() % 7;
        stateA.hand[stateA.whoseTurn][0]= adventurer;
        stateA.deckCount[stateA.whoseTurn] = rand() % MAX_DECK;
        stateA.discardCount[stateA.whoseTurn] = rand() % MAX_DECK;
        stateA.handCount[stateA.whoseTurn] = rand() % MAX_HAND;

        memcpy(&stateB, &stateA, sizeof(struct gameState));
        a = cardEffect(adventurer, 0, 0, 0, &stateA, 1, 0);
        bool result = false;

        for(j = 0; j < stateA.handCount[stateA.whoseTurn]; j++){
            if(stateA.hand[stateA.whoseTurn][j] == 6){
                result = true;
                break;
            }
        }
        results[count++] = assertTrue("numActions", stateA.numActions, stateB.numActions);
        results[count++] = assertTrue("discardCount", stateA.discardCount[stateA.whoseTurn], stateB.discardCount[stateB.whoseTurn]);
        results[count++] = assertTrue("handCount", stateA.handCount[stateA.whoseTurn], stateB.discardCount[stateB.whoseTurn]);
        results[count++] = assertTrue("supplyCount", stateA.supplyCount[gold], 30);
        results[count++] = assertTrue("goldCount", result, false);
    }
    printFinalResult(results, TESTS);
    return 0;
}
