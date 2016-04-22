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
	- \fancyfoot[L]{HW 6 - CSC335}
	- \fancyfoot[C]{}
	- \fancyfoot[R]{\thepage}
---

"Brute Force"
==============

In the basic sense, all exponent means is multiply this number by itself n times.
That is all this algorithm does.

```java
	public int powerN(int base, int n) {
		
		int ans = base;
		for (int i=1; i<n; ++i) {
			
			ans *= base;
		}
		return ans;
	}
```

Number of Multiplications
-------------------------

Algorithm grows linearly with the value of $n$.

$$
\begin{aligned}
	powerN(1) &= 0 \\
	powerN(n) &= \sum_{i=1}^{n-1} 1 \\
	          &= (n-1)*1 \\
			  &= n-1\: \mbox{multiplications}\\
\end{aligned}
$$

Recursive, One Level
====================

```java
	public int powerN(int base, int n) {

		if (n < 2) {
			
			return base;
		}

		return base * (int base, n-1);
	}
```

Number of Multiplications
-------------------------

It's not much different from the iterative looping solution.

$$
\begin{aligned}
	powerN(1) &= 0 \\
	powerN(n) &= powerN(n-1) + 1 \\
	          &= powerN(n-2) + 1 + 1 \\
			  &= powerN(1) + ... + 1 \\
			  &= n-1\: \mbox{multiplications}
\end{aligned}
$$

Transformation
==============

When drawing out a tree of multiplications, one can see that if the exponent is a power of 2, it is possible to reduce the multiplications by multiplying the base and dividing the exponent by two.

In essence this algorithm virtually splits the numerous multiplications and merges them.

Technically this is a transformation of the problem since it diverts away from the classic sense of the problem by solving it using different math procedures.

Unlike the above recursive solution. This one is faster because of this property.
To fix uneven exponents, one just needs to multiply the result of the next recursion by the current base local to that function.

```java
	public int powerN(int base, int n) {
		
		if (n < 2) {
			
			return base;
		}

		if (n & 1 == 1) {

			return base * powerN(base*base, n/2);
		}
		else {

			return powerN(base*base, n/2);
		}
	}
```

Number of Multiplications
-------------------------

Unlike the other ones, this one significantly reduces the amount of work done as it is not linear anymore. The problem becomes logarithmic instead.

Assume the exponent is a number that is a power of 2. If it isn't it makes the analysis slightly harder due to two different code paths being taken.

$$
\begin{aligned}
	powerN(1) &= 0 \\
	powerN(n) &= powerN\Big(\frac{n}{2}\Big) + 1 \\
	          &= powerN\Big(\frac{n}{4}\Big) + 1 + 1 \\
			  &= powerN\Big(\frac{n}{2^{2}}\Big) + 1 + 1 \\
			  &= powerN\Big(\frac{n}{2^{\log_2{n}}}\Big) + \log_2{n} \\
			  &= powerN(1) + \log_2{n} \\
			  &= \log_2{n}\: \mbox{multiplications} \\
\end{aligned}
$$
