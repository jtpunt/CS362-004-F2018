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
#define PER_TEST  5
#define MAX_TESTS 5
int main(int argc, char** argv) {
    srand(time(NULL));
    struct gameState stateA, stateB;
    int a, i, j;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    printf ("Testing Adventurer card\n");
    bool results[MAX_TESTS * PER_TEST];
    int count = 0;
    for(i = 0; i < MAX_TESTS; i++){
        initializeGame(2, k, 4, &stateA);

        stateA.numActions = rand() % 10;
        stateA.handCount[stateA.whoseTurn] = rand() % MAX_HAND;
        stateA.deckCount[stateA.whoseTurn] = rand() % MAX_DECK;
        stateA.discardCount[stateA.whoseTurn] = rand() % MAX_DECK;
        int prev_discard_count = stateA.discardCount[stateA.whoseTurn];
        int prev_hand_count = stateA.handCount[stateA.whoseTurn];
        memcpy(&stateB, &stateA, sizeof(struct gameState));
        a = cardEffect(adventurer, 0, 0, 0, &stateA, 1, 0);
        bool result = false;

        for(j = 0; j < stateA.handCount[stateA.whoseTurn]; j++){
            if(stateA.hand[stateA.whoseTurn][j] == 6){
                result = true;
                break;
            }
        }
        int after_discard_count = stateA.discardCount[stateA.whoseTurn];
        int after_hand_count = stateA.handCount[stateA.whoseTurn];
        results[count++] = assertTrue("numActions", stateA.numActions, stateB.numActions);
        results[count++] = assertTrue("discardCount", stateA.discardCount[stateA.whoseTurn], stateB.discardCount[stateB.whoseTurn] + (after_discard_count - prev_discard_count));
        results[count++] = assertTrue("handCount", stateA.handCount[stateA.whoseTurn], stateB.discardCount[stateB.whoseTurn] - (stateB.discardCount[stateB.whoseTurn] - prev_hand_count + prev_hand_count - after_hand_count));
        results[count++] = assertTrue("supplyCount(gold)", stateA.supplyCount[gold], 30);
        results[count++] = assertTrue("goldCount = 0", result, false);
        results[count++] = assertTrue("value returned", a, 0);
    }
    printFinalResult(results, MAX_TESTS);
    return 0;
}
