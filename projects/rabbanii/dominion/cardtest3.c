#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// adventurer test

int main(int argc, char** argv) 
{
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int choice1 = 0, choice2 = 0, choice3 = 0;
	initializeGame(2, k, 4, &G);
	assert(cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL) == 0);
	printf("TEST SUCCESSFULLY COMPLETED\n");

	return 0;
}