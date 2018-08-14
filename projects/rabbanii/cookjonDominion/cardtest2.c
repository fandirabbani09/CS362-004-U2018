#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// village tests

int main(int argc, char** argv) 
{
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int actions;

	initializeGame(2, k, 2, &G);
	actions = G.numActions;

	assert(G.numActions == actions + 2);

	printf("TEST SUCCESSFULLY COMPLETED\n");
	
	return 0;

}
