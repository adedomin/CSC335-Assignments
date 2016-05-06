#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(int argc, char **argv) {
	argv++; argc--;

	uint32_t quarter_limit = -1;
	uint32_t dime_limit = -1;
	uint32_t nickel_limit = -1;
	uint32_t penny_limit = -1;

	int32_t quarters = 0;
	int32_t dimes = 0;
	int32_t nickels = 0;
	int32_t pennies = 0;

	int32_t amount_orig = (int32_t) atoi(argv[0]);
	int32_t amount = amount_orig;

	if (argc == 5) {
		quarter_limit = (uint32_t) atoi(argv[1]);
		dime_limit = (uint32_t) atoi(argv[2]);
		nickel_limit = (uint32_t) atoi(argv[3]);
		penny_limit = (uint32_t) atoi(argv[4]);
	}

	quarters = amount / 25;
	if (quarters > quarter_limit) {
		quarters = quarter_limit;
		amount -= quarter_limit*25;
	}
	else {
		amount %= 25;
	}
	dimes = amount / 10;
	if (dimes > dime_limit) {
		dimes = dime_limit;
		amount -= dime_limit*10;
	}
	else {
		amount %= 10;
	}
	nickels = amount / 5;
	if (nickels > nickel_limit) {
		nickels = nickel_limit;
		amount -= nickel_limit*5;
	}
	else {
		amount %= 5;
	}
	pennies = amount;
	if (pennies > penny_limit) {
		printf("COULD NOT MAKE CHANGE\n");
		exit(1);
	}

	printf("%" PRId32 " amount\n", amount_orig);
	printf("%" PRId32 " quarters\n", quarters);
	printf("%" PRId32 " dimes\n", dimes);
	printf("%" PRId32 " nickels\n", nickels);
	printf("%" PRId32 " pennies\n", pennies);
}
