---
title: Homework 5 - CSC335
author:
    - Anthony DeDominic [\<dedominica@my.easternct.edu\>](mailto:dedominica@my.easternct.edu)
date: \today{}
geometry: margin=3cm
fontfamily: mathpazo
header-includes:
	- \usepackage{fancyhdr}
	- \pagestyle{fancy}
	- \fancyfoot[L]{HW 5 - CSC335}
	- \fancyfoot[C]{}
	- \fancyfoot[R]{\thepage}
---

Finding Minimum and Maximum
===========================

'Bruteforce' Algorithm
----------------------

Given an array of sortable and comparable elements, such as integers, then the fastest way to find the minimum and maximum is to scan through every element twice.

Below is a mathematical way to solve the problem in the most straightforward way.
It starts from the top most element and then reduces them til only the smallest and largest value are left.

Since it had to be singley recursive the algorithm has to process the data as a series of tuples.
The tuples don't change the amount of comparisons.

```Haskell
min_max :: Ord a => [a] -> Maybe (a, a)

min_max [] = Nothing
min_max (x:xs) = Just $
	foldr (\(x,a) (y,b) -> 
		if x > y then 
			(if a < b then 
				(y, b) 
			else 
				(y, a)) 
		else 
			(if a < b then 
				(x, b) 
			else 
				(x, a))) 
	(x,x) (zip xs xs)
```

Comparisons - All Cases
-----------------------

All three cases are exactly the same and that is because no matter what, the only way to guarantee that the minimum and maximum were found is to compare EVERY element in the array.

The algorithm must make two n compares on the list. One is to find the maximum and the other is to find the minimum.

### Proof

$$
\begin{aligned}
	\textsc{Base case:} & \\
	T(0) &= 0 \\
	T(1) &= 2 \\
	\textsc{Recursive step:} & \\
	T(n) &= T(n-1) + 2 \\
	     &= T(n-2) + 2 + 2 \\
		 &= T(n-(n-1)) + ... + 2 \\
		 &= 2n \\
\end{aligned}
$$

Ultimately, the algorithm has a time complexity of O(n). This because it makes roughly 2n scans to find both the minimum and maximum.

'Divide and Conquer' Algorithm
------------------------------

The Second function must solve the same problem, but has to break the S-Expression into halves until they are only one element long.
The merge step is similar to the bruteforce logic but it doesn't reduce the problem using a high order function like a fold.

Ultimately, this function isn't optimal as lists in Haskell are essentially cons cells like (a, (a, (a, null))) and thus, splitting requires N runs to copy the first half and drop the first half to get the last half.

```Haskell
div_min_max'split :: Ord a => [a] -> ([a], [a])
div_min_max'merge :: Ord a => (a,a) -> (a,a) -> (a,a)
div_min_max :: Ord a => [a] -> (a, a)

div_min_max'split xs = (take n xs, drop n xs)
	where 
	n = (length xs) `div` 2

div_min_max'merge (x,a) (y,b) =
	(if x > y then
		(if a < b then
			(y, b)
		else
			(y, a))
	else
		(if a < b then
			(x, b)
		else
			(a, a)))

div_min_max xs
	| (length xs) > 1 = 
		div_min_max'merge 
			(div_min_max left)
			(div_min_max right)
	| otherwise = (xs !! 0, xs !! 0)
	where
	(left, right) = div_min_max'split xs
```

Comparisons - All Cases
-----------------------

Just like above, this equation MUST scan through all the elements to be assured the results are correct.
Similar to Mergesort, this equation has a time complexity that is the same in any case.

Overall this equation has a time complexity of $O(n\log{n})$.
This is because the process of splitting the linked list into equal halves requires at least N scans.
Given that the size of N shrinks by a factor of two every level down, the split must occur $\log{n}$ times.
Thus the splitting operation multiplied by the amount of times the array is split into half gives you ~$n\log{n}$ runs.
The "merge" part of the equation is constant number of comparisons.
It takes two compares to complete the merge.
Multiply 2 by the $n\log{n}$ gives you a rough idea of the amount of operations the function runs through.

### Proof

$$
\begin{aligned}
	\textsc{Base case:} & \\
	T(1) &= 1 \\
	\textsc{Recursive step:} & \\
	T(n) &= 2(n + T(\frac{n}{2}) + T(\frac{n}{2})) \\
	T(n) &= 2(n + 2(T(\frac{n}{2}))) \\
	T(n) &= 2(n + 2(T(\frac{n}{2}))) \\
	T(n) &= 2(n + 2(2T(\frac{n}{4})+\frac{n}{2})) \\
	T(n) &= 2(n + 2(2(2T(\frac{n}{8})+\frac{n}{4})+\frac{n}{2})) \\
	T(n) &= 2(n + 2(2(2T(\frac{n}{8})+\frac{n}{4})+\frac{n}{2})) \\
	T(n) &= 2(n + 2(2(2T(\frac{n}{8})+\frac{n}{4})+\frac{n}{2})) \\
	T(n) &= 2(n + 2(2(2(...2T(1)+2)+\frac{n}{2})) \\
	T(n) &= 2(n + n\log{n}) \\
	T(n) &= 2n + 2n\log{n} \\
\end{aligned}
$$

Overall
-------

In this case, the bruteforce algorithm is better than the divide and conquer method.
The divide and conquer function is hindered by how haskell's lists work, they are linked lists.
In an ideal implementation, both should be very similar in performance.
An ideal implementation would allow for constant time list splitting, unlike mine which takes N operations.

Ultimately, there is no superior way of solving this problem, since all the methods result in the same amount of N comparisons.
In my opinion however, I believe that a simple iterative or recursive solution is much easier to understand.
