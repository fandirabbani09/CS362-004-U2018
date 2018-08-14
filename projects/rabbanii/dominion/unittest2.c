#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// shuffle test

int main(int argc, char **argv)
{
	srand(time(NULL));
	int numplayers = rand() % (MAX_PLAYERS - 1) + 1;
	struct gameState G;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	initializeGame(numplayers, k, rand(), &G);

	int numtests = 1000;
	int times_unshuffled = 0;
	for (int i = 0; i < numtests; i++)
	{
		struct gameState O;
		memcpy(&O, &G, sizeof(struct gameState)); // saving original state

		int player = rand() % numplayers;
		shuffle(player, &G);
		if (memcmp(&O.deck[player], &G.deck[player], sizeof(int)*MAX_DECK) != 0) times_unshuffled++;
	}

	assert(times_unshuffled < numtests / 2); // assert that shuffle() changed the card order at least half of the time.

	printf("TEST SUCCESSFULLY COMPLETED\n");
}