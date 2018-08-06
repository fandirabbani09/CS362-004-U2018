#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// getCost tests
 
int test1()
{
	printf("Testing getCost for coins\n");
	assert(getCost(copper) == 0);
	assert(getCost(silver) == 3);
	assert(getCost(gold) == 6);
	printf("TEST SUCCESSFULLY COMPLETED\n");
	return 0;
}

int test2()
{
	printf("Testing getCost for places\n");
	assert(getCost(estate) == 2);
	assert(getCost(province) == 8);
	assert(getCost(gardens) == 4);
	assert(getCost(mine) == 5);
	printf("TEST SUCCESSFULLY COMPLETED\n");
	return 0;
}

int test3()
{
	printf("Testing incorrect values\n");
	assert(getCost(silver) != 0);
	assert(getCost(steward) != 0);
	printf("TEST SUCCESSFULLY COMPLETED\n");
}

int test4()
{
	printf("Testing getCost for smithy and adventurer\n");
	assert(getCost(smithy) == 4);
	assert(getCost(adventurer) == 6);
	printf("TEST SUCCESSFULLY COMPLETED\n");
	return 0;
}

int main () 
{
	// int i, n, r, p, deckCount, discardCount, handCount;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	// struct gameState G;

	printf ("Unit test 1.\n");

	test1();
	test2();
	test3();
	test4();

	return 0;
}
