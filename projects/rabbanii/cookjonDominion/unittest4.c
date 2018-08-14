#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// isGameOver tests

int main() 
{
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int s;
	initializeGame(2, k, 2, &G);
	G.supplyCount[province] = 0;
	s = isGameOver(&G);
	assert(s == 1);
	printf("TEST SUCCESSFULLY COMPLETED\n");

	G.supplyCount[1] = 0;
	G.supplyCount[4] = 0;
	G.supplyCount[7] = 0;
	s = isGameOver(&G);
	assert(s == 1);
	printf("TEST SUCCESSFULLY COMPLETED\n");

	return 0;
}
