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
#define PER_TEST  3
#define MAX_TESTS 5
int main(int argc, char** argv) {
    srand(time(NULL));
    struct gameState stateA, stateB;
    int a, i;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    printf ("Testing Smithy card\n");
    bool results[MAX_TESTS * PER_TEST];
    int count = 0;
    for(i = 0; i < MAX_TESTS; i++){
        initializeGame(2, k, 4, &stateA);
        stateA.handCount[stateA.whoseTurn] = rand() % MAX_HAND;
        int cardsOnHand = numHandCards(&stateA); // cardsOnHand before calling the card's function - which will increase the # of cards on hand by 5

        memcpy(&stateB, &stateA, sizeof(struct gameState));
        a = cardEffect(smithy, 0, 0, 0, &stateA, 1, 0);

        results[count++] = assertTrue("cardsOnHand", cardsOnHand + 3 - 1, numHandCards(&stateA));
        results[count++] = assertTrue("value returned", a, 0);
        results[count++] = assertTrue("cardsOnHand A vs B", numHandCards(&stateA), numHandCards(&stateB) + (numHandCards(&stateA) - numHandCards(&stateB)));
    }
    printFinalResult(results, MAX_TESTS);
    return 0;
}
