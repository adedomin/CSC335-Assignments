---
title: Homework 4 CSC335
author:
    - Anthony DeDominic \<dedominica@my.easternct.edu\>
date: \today{}
geometry: margin=3cm
fontfamily: mathpazo
---

Algorithm Used
--------------

```Haskell
	hw_assign :: Ord a => Int -> [a] -> a

	hw_assign pos (x:xs) 
		| pos < len = hw_assign pos ys
		| pos > len = hw_assign new_pos zs
		| otherwise = x
		where
			ys  = filter (<x) xs
			zs  = filter (>=x) xs
			len = length ys
			new_pos = pos - (len - 1)
```

Comparisons - Worst Case
------------------------

Because this algorithm is like Quicksort, it can potentially have a comparison complexity of $O(n^{2})$.
This is because in the worst case, the partioning can lead to one array having all the elements and the other being completely empty.
This is the case if the list of elements is already sorted in favor of smallest to largest.

### Proof

Since the algorithm above is recursive it can be shown how many compares take place in the worst case.
Since partioning is done in a fashion that requires 2 entire $n$ scans, the base case of T(1) is at least 2 compares.

$$
\begin{aligned}
	\textsc{Base case:} & \\
	T(1) &= 2 \\
	\textsc{Recursive step:}
	T(n) &= 2n + T(0) + T(n-1), n \gt 1 \\
	     &= 2n + (2n-1) + T(0) + T(n-2) \\
		 &= 2n + (2n-1) + (2n-2) + T(0) + T(n-3) \\
		 &= 2n + (2n-1) + ... + T(0) + T(1) \\
		 &= 2n + (2n-1) + ... + 2 \\
		 &= \frac{2n(n-1)}{2} \\
		 &= n^{2} - 2 \\
		 &= O(n^{2}) \\
\end{aligned}
$$

As seen above, the algorithm in its worse case runs roughly $n^{2}-2$ comparisons. This is mainly because partioning takes at least 2n scans per run.

Comparisons - Best Case
-----------------------

In it's best case, unlike quicksort, it approaches linear time.
This is because the algorithm only descends into one list.

### Proof

Below is assuming the best case is that the list of elements can be divided into halves.
This creates a geometric sequence.

$$
\begin{aligned}
	\textsc{Base case:} \\
	T(1) &= 2 \\
	\textsc{Recursive step:} \\
	T(n) &= 2n + T(\frac{n}{2}) + T(\frac{n}{2}), n \gt 1 \\
	     &= 2n + (n + T(\frac{n}{4})) + (n + T(\frac{n}{4})) \\
	     &= 2n + (n + \frac{n}{2} + T(\frac{n}{8})) + (n + \frac{n}{2} + T(\frac{n}{8})) \\
	     &= 2n + (n + \frac{n}{2} + \frac{n}{4} + ... + 1) + (n + \frac{n}{2} + \frac{n}{4} + ... + 1) \\
	     &= 2n + 2(n + \frac{n}{2} + \frac{n}{4} + ... + 1) \\
	     &= 2n + 2(2n) \\
	     &= 2n + 4n \\
	     &= 6n \\
	     &= O(n) \\
\end{aligned}
$$

The algorithm in the best case is linear, and makes roughly 6n comparisons.

Comparisons - Average Case
--------------------------


