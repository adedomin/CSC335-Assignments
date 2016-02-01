Homework 1 
===========

By Anthony DeDominic [\<dedominica@my.easternct.edu\>](mailto:dedominica@my.easternct.edu)
---------------------

### Bruteforce GCD Algorithm
| | GCD(int,int) | Recursive Depth | GCD |
|:-- | :--- | :--- | :--- |
| Worst | GCD(19227 , 18553) | 18552 | 1 | 
| Best | GCD(1102 , 17464 | 1100 | 2 |
| Average | ?? | 7240 | ?? |

#### Euclidean GCD Algorithm
| | GCD(int, int) | Recursive Depth | GCD |
|:--- | :--- | :--- | :--- |
| Worst | GCD(8504 , 13883) | 13 | 1 |
| Best | GCD(7647 , 7648) | 2 | 1 |
| Average | ?? | 8 | ?? |

Time Complexity of the Bruteforce GCD Algorithm
-----------------------------------------------

### O(min(N,M))

The time complexity of the bruteforce algorithm is linearly proportional to the min(N, M); where N is an integer and M is another integer.
This is because the algorithm goes from the smallest of the two numbers and recursively counts downwards from the starting value of of min(N, M) until it reaches the base case of 1 which will always devise number 1 and 2 completely with no remainders.


Time Complexity of the Euclidean GCD Algorithm
-----------------------------------------------

### O()
