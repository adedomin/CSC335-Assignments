---
title: Homework 6 - CSC335
author:
    - Anthony DeDominic [\<dedominica@my.easternct.edu\>](mailto:dedominica@my.easternct.edu)
date: \today{}
geometry: margin=3cm
fontfamily: mathpazo
header-includes:
	- \usepackage{fancyhdr}
	- \pagestyle{fancy}
	- \fancyfoot[L]{HW 7 - CSC335}
	- \fancyfoot[C]{}
	- \fancyfoot[R]{\thepage}
---

Making Change 
=============

Algorithm
---------

This problem is relatively simple.
Because coins can potentially be limited, extra logic was added to handle such situations.
As seen below, this problem can be solved in constant time.

Note that it is assumed that integer division rules apply and truncation occurs.

```c
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
```

All cases
---------

This problem is CONSTANT TIME. 
Because of this, it has a big O of $O(1)$.
This problem finds the best possible change scenario, as in the least amount of coins given, because it starts from the largest denomination and goes downwards.
The larger denominations will require less coinage to fulfill.

To handle case of coin shortages or unavailability, the logic checks to see if the change made is possible with if checks.
If they are not it makes the BEST possible for the denomination by setting the amount to the maximum coins available.
Then, it subtracts that value from amount for finding the amount of the next lowest denomination.

Proof - Worst case
------------------

This algorithm makes 16 operations for the worst case.
This ignores things like initial setup of the variables, their values and so on.
This assumes that change can not be made for the given N as that is the only case where all four if statements will return true and cause the most amount of operations

$$
\begin{aligned}
	f(n) &= 16\: \mbox{operations} \\
         &= O(1) \\
\end{aligned}
$$

Proof - Best Case
-----------------

Assuming change can be made for all denominations, then there are only 10 operations called.

$$
\begin{aligned}
	f(n) &= 10\: \mbox{operations} \\
	     &= O(1) \\
\end{aligned}
$$

Results of 31, 42 and 57
------------------------

amount quarters dimes nickels pennies
------ -------- ----- ------- -------
    31        1     0       1       1
    42        1     1       1       2
    57        2     0       1       2
------ -------- ----- ------- -------

Raw output
----------

	./change 31         
	31 amount
	1 quarters
	0 dimes
	1 nickels
	1 pennies

	./change 42
	42 amount
	1 quarters
	1 dimes
	1 nickels
	2 pennies

	./change 57
	57 amount
	2 quarters
	0 dimes
	1 nickels
	2 pennies

