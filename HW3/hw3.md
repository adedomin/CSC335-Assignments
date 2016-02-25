---
title: Homework 3 CSC335
author:
    - Anthony DeDominic \<dedominica@my.easternct.edu\>
date: \today{}
geometry: margin=3cm
header-includes:
	- \usepackage{mathpazo}
---

### 1)

This equation computes the sum of n, minus the series up to m, times 5.

This equation computes $sum = \sum\limits_{i=m}^{n}\sum\limits_{j=1}^{i} 5$.
The second summation series can be simplified as $i\times 5$.
Since 5 is constant, all it would do is add 5 to the sum, $i$ times, which is equivalent to multiplying 5 by $i$.
So you get $\sum\limits_{i=m}^{n} i\times 5$.
This equation gives you the summation series $(m + (m+1) + (m+2) + (m+3) + ... + n)\times 5, m<n$.
$m$ is merely removing the sequence $1 + 2 + ... + m-1$ from the above sequence.
Thus, this sequence can be written as $((1 + 2 + 3 + ... + n) - (1 + 2 + 3 + ... + (m-1)))\times 5$.
The sequence above is logically equivalent to $(\frac{n(n+1)}{2}-\frac{(m-1)((m-1)+1)}{2})\times 5$.
dividing the above by 5 gives us the amount of times $sum = sum + 5$ in the code is ran, so $\frac{n(n+1)}{2}-\frac{(m-1)((m-1)+1)}{2}$ additions and assignments.
Because $n^{2}$ is the largest factor, this equation has a time complexity of $\Theta(n^{2})$.

### 1) Analysis

The number of times the code $sum = sum + 5$ is called is $\frac{n(n+1)}{2}-\frac{(m-1)((m-1)+1)}{2}$

$$
\begin{aligned} 
    Sum(0,1) & = 1 \\
	Sum(m,n) & = \sum\limits_{i=m}^{n}\sum\limits_{j=1}^{i} 1 \\
	           & = \sum\limits_{i=m}^{n} i \\
			   & = m + (m+1) + (m+2) + ... + n \\
			   & = 1 + 2 + 3 + ... + n - 1 + 2 + 3 + ... + (m-1) \\
			   & = \frac{n(n+1)}{2}-\frac{(m-1)((m-1)+1)}{2} \\
			   & = \Theta(n^{2}) \\
\end{aligned}
$$

### 2) Definitions

where head is the n-1th element in a list, the last element.
where tail is the array containing all but the n-1th element.
where n is the size of the array.
where array's are zero indexed, thus n-1th element.

### 2) Description

This equation tries to find the maximum number in the series by shrinking the problem set linearly by a factor of 1.
The value of variable becomes the result of $Recursive(tail(A))$, where $A$ is a list of values.
The $tail(A)$ function parameter effectively is pushing to the next function down, it's own local copy of $A$.
This recursion occurs untill there is only one element left and thus, no more tail of the functon's own local $A$.
This is the function's base case and it will return this last element to the second last function call; the function then assigns this return to the variable value.
From the second last call, it will check if the node before it (the local head of A) is less than value in value.
If it is, this node is pruned; else the function returns the local $head(A)$
thus, the third function gets the bigger of the two element's in it's $A$'s tail and assigns it to value.
value is then checked against the third function's $head(A)$.

This process occurs until we get back to the highest level where it all started.
At the end, the largest number of the initial $A$'s tail is returned back to the initial caller where it competes against the $head(A)$.

At the end, the function returns the largest number held in A.

### 2) Analysis:

This function has a big O of $\Theta(n)$.
as in, the list is broken apart in a factor of 1 and processed as such.
the function makes n-1 comparisons to find the largest value.

$$
\begin{aligned}
	Recursive([1])      & = 0 \\
	Recursive([0..n-1]) & = Recursive([0..n-2]) + 1, n > 1 \\
	                    & = (Recursive([0..n-3]) + 1) + 1 \\
	                    & = (Recursive([0..(n-(n-1))]) + 1 + 1 + ... + 1) + 1 \\
	                    & = n - 1 \\
                        & = \Theta(n) \\
\end{aligned}
$$
