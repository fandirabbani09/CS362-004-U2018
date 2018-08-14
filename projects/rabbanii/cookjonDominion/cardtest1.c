#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// smithy test

int main(int argc, char** argv) 
{
	struct gameState G;
	G.numActions = 1;
	G.whoseTurn = 0;
	G.handCount[0] = 1;
	G.hand[0][0] = smithy;
	G.discardCount[0] = 0;
	G.deckCount[0] = 3;
	G.deck[0][0] = province;
	G.deck[0][1] = province;
	G.deck[0][2] = province;
	playCard(0, 0, 0, 0, &G);
	assert(G.handCount[0] == 3);
	assert(G.deckCount[0] == 0);
	assert(G.hand[0][0] == province);
	assert(G.hand[0][1] == province);
	assert(G.hand[0][2] == province);
	assert(G.numActions == 0);

	return 0;
}