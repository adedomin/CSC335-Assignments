// HW 1 CSC 335
// by Anthony DeDominic
// for CSC335 -> Spring 2016
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0

#define BRUTE '\0'
#define EUCLID '1'
#define MAX_PAIRS 100
#define BIGGEST_RAND 20000
#define SMALLEST_RAND 1000
#define assignment_rand() rand() % (BIGGEST_RAND-SMALLEST_RAND) + SMALLEST_RAND
#define max(x) x.num1 > x.num2 ? x.num1 : x.num2
#define min(x) x.num1 > x.num2 ? x.num2 : x.num1

// struct with
// num1 -> a number
// num2 -> a number
// gcd  -> the gcd
// euclid_count -> number of
//                 iterations
//                 for euclid
// brute_count  -> number of
//                 iterations
//                 for bruteforce
struct numpairs {

	int num1;
	int num2;
	int gcd;
	int euclid_count;
	int brute_count;
};
typedef struct numpairs numpairs;

// A tuple with
// gcd   -> the gcd
// count -> number of 
//          iterations
//          to run algo
struct gcd_count {

	int gcd;
	int count;
};
typedef struct gcd_count gcd_count;

// creates a num pair with random numbers
numpairs construct_rand_num_pair() {

	numpairs numpair;
	numpair.num1 = assignment_rand();
	numpair.num2 = assignment_rand();
	numpair.gcd  = 1;
	numpair.euclid_count = 0;
	numpair.brute_count  = 0;

	return numpair;
}

// GCD using euclid' algo - recursive
// large   -> larger of the two numbers
// small   -> smaller of the two numbers
// count   -> number of times this algo ran
// RETURNS -> a struct with the gcd and the count
gcd_count gcd_eculid(int large, int small, int count) {
	
	if (small == 0) {
		
		return (gcd_count) {large, count+1};
	}

	return gcd_eculid(small, (large % small), count+1);
}

// GCD using a bruteforce method - recursive
// large   -> larger of the two numbers
// small   -> smaller of the two numbers
// gcd     -> possible gcd, decrements by 1
// count   -> number of times this algo ran
// RETURNS -> a struct with the gcd and the count
gcd_count gcd_brute(int large, int small, int gcd, int count) {

	if (large % gcd == 0 && small % gcd == 0) {

		return (gcd_count) {gcd, count+1};
	}

	return gcd_brute(large,small,gcd-1,count+1);
}

// the GCD algorithm
// num1    -> int
// num2    -> int
// type    -> the GCD algorithm to run
//            SEE BRUTE and EUCLID definition
// RETURNS -> a tuple with the gcd and the count
gcd_count GCD(int num1, int num2, char type) {

	// ints must be greater than 0
	// ints must not be equal as well
	if ((num1 < 1 && num2 < 1) || num1 == num2) {
		printf("An error occured: GCD Arguments must be greater than zero or not equal to each other.");
		exit(1);
	}

	if (num2 > num1) {
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	// if user passed BRUTE
	if (!type) {
		
		return gcd_brute(num1,num2,num2,0);
	}

	// if user passed any other char
	return gcd_eculid(num1,num2,0);
}

int main(void) {

	srand(time(NULL));
	numpairs pairs[MAX_PAIRS];

	// indexes in pairs
	int slowest_euclid = 0; 
	int fastest_euclid = 0;
	int average_euclid = 0;

	// indexes in pairs
	int slowest_brute  = 0;
	int fastest_brute  = 0;
	int average_brute  = 0;

	// init pairs[]
	for (int i=0; i<MAX_PAIRS; ++i) {
		
		pairs[i] = construct_rand_num_pair();

	}

	// run two different gcd algorithms
	// get number of operations it takes to find the gcd
	for (int i=0; i<MAX_PAIRS; ++i) {

		gcd_count g_c;

		g_c = GCD(pairs[i].num1,pairs[i].num2, BRUTE);
		pairs[i].gcd = g_c.gcd;
		pairs[i].brute_count = g_c.count;

		if (pairs[i].brute_count > pairs[slowest_brute].brute_count) {
			slowest_brute = i;
		}
		if (pairs[i].brute_count < pairs[fastest_brute].brute_count) {
			fastest_brute = i;
		}

		g_c = GCD(pairs[i].num1,pairs[i].num2, EUCLID);
		pairs[i].gcd = g_c.gcd;
		pairs[i].euclid_count = g_c.count;

		if (pairs[i].euclid_count > pairs[slowest_euclid].euclid_count) {
			slowest_euclid = i;
		}
		if (pairs[i].euclid_count < pairs[fastest_euclid].euclid_count) {
			fastest_euclid = i;
		}
	}

	// create average number of operations
	for (int i=0; i<MAX_PAIRS; ++i) {
		
#if DEBUG
		printf("GCD(%d, %d) = %d:\t brute op count: %d\teuclid op count: %d\n",
				pairs[i].num1,pairs[i].num2,
				pairs[i].gcd,
				pairs[i].brute_count,
				pairs[i].euclid_count);
#endif

		average_brute += pairs[i].brute_count;
		average_euclid += pairs[i].euclid_count;
	}

	// divid by pairs size
	average_brute /= MAX_PAIRS;
	average_euclid /= MAX_PAIRS;

	// print results
	printf("BRUTEFORCE\n\n");
	printf("The most number of iterations used is (%d) for GCD(%d , %d) = %d.\n",
			pairs[slowest_brute].brute_count,
			pairs[slowest_brute].num1,pairs[slowest_brute].num2,
			pairs[slowest_brute].gcd);

	printf("The least number of iterations used is (%d) for GCD(%d , %d) = %d.\n",
			pairs[fastest_brute].brute_count,
			pairs[fastest_brute].num1,pairs[fastest_brute].num2,
			pairs[fastest_brute].gcd);

	printf("The average number of iterations used for all %d pairs is (%d).\n\n",
			MAX_PAIRS,average_brute);

	printf("EUCLID\n\n");
	
	printf("The most number of iterations used is (%d) for GCD(%d , %d) = %d.\n",
			pairs[slowest_euclid].euclid_count,
			pairs[slowest_euclid].num1,pairs[slowest_euclid].num2,
			pairs[slowest_euclid].gcd);
	
	printf("The least number of iterations used is (%d) for GCD(%d , %d) = %d.\n",
			pairs[fastest_euclid].euclid_count,
			pairs[fastest_euclid].num1,pairs[fastest_euclid].num2,
			pairs[fastest_euclid].gcd);

	printf("The average number of iterations used for all %d pairs is (%d).\n\n",
			MAX_PAIRS,average_euclid);

	return 0;
}

