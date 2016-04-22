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
	powerN(n) &= \sum_{i=1}^{n} 1 \\
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

not much different from the iterative looping solution.
It is still $n$.

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

Unlike the other ones, this one significantly reduces the amount of work done as it is not linear anymore. the problem becomes logorithmic instead.

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

If you assume $n$ isn't a power of 2, the extra amount of work is very minimal.
