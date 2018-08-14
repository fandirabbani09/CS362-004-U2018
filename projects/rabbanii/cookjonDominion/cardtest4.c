#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>

// council room test

int main(int argc, char** argv) 
{
	struct gameState G;
	struct gameState *g = &G;
	int returnValue;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int player1 = 0;
	int player2 = 1;
	int prev1;
	int prev2;
	int new1;
	int new2;
	returnValue = initializeGame(2, k, 4, g);
	assert(returnValue == 0);

	prev1 = G.deckCount[player1]; // save original state
	prev2 = G.deckCount[player2];
	
	cardEffect(council_room, 0, 0, 0, g, 0, 0); // use card and store new state
	new1 = G.deckCount[player1];
	new2 = G.deckCount[player2];

	assert(new1 == prev1 - 4); 	// make sure all is well
	assert(new2 == prev2 - 1);
	printf("TEST SUCCESSFULLY COMPLETED\n");

	return 0;
}