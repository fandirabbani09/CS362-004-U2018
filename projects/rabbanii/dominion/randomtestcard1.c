#include "dominion.h"
#include "rngs.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_TESTS 1000																								// Define maximum amount of tests to run

int main()
{
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };	// Initiate hand

	struct gameState G;																								// Initiate game state
	struct gameState O;																								// Initiate game state copy

	srand(time(NULL));																								// Call random number generator function 
	int seed = rand() % MAX_TESTS;																					// Seed random number of tests below defined MAX_TESTS

	for (int i = 0; i < seed; i++)																					// Run test suite the number of times seeded above
	{
		int numPlayers = rand() % (MAX_PLAYERS - 1) + 2;															// Random number of players between 2 and 4
		initializeGame(numPlayers, k, seed, &G);																	// Begin game
		int currentPlayer = rand() % numPlayers;																	// Randomly assign current player
		G.whoseTurn = currentPlayer;																				// Reference whoseTurn property
		G.deckCount[currentPlayer] = rand() % MAX_DECK;																// Initiate random deck size

		int choice1 = rand() % MAX_DECK;																			// Initiate random card 1
		int choice2 = rand() % MAX_DECK;																			// Initiate random card 2
		int choice3 = rand() % MAX_DECK;																			// Initiate random card 3
		int handPos = rand() % MAX_HAND;																			// Randomly initate selector
		int bonus = rand() % MAX_DECK;																				// Initiate bonus card

		memcpy(&O, &G, sizeof(struct gameState));																	// Make game state copy for asserts to reference later

		cardEffect(smithy, choice1, choice2, choice3, &G, handPos, &bonus);											// Run smithy card

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
	}
	printf("TEST SUCCESSFULLY COMPLETED\n");
	return 0;
}