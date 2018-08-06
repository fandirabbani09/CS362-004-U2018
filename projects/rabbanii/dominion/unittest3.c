#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// whoseTurn tests

int main() 
{
	struct gameState G;
	int turn = 0;
	int s = 0;

	for (int i = 0; i < 15; i++) 
	{
		G.whoseTurn = turn;
		s = whoseTurn(&G);
		assert(s == turn);
		turn++;
	}
	printf("TEST SUCCESSFULLY COMPLETED\n");
	return 0;
}