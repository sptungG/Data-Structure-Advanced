/*
Given a tree T (T is given by the list of edges).
 Let 1 be the root of T. For each node x of T such that x≠1,
 Find the parent of x.
  (Parent of a node x is the node next to x 
   in the simple path from x to the root of tree.)

Input
 First line contains n: number of nodes of T
 n−1 next line, each line contains an edge of T: u v

Output
 Contains n−1 numbers, i-th number is the parent of node i+1

Scoring
 1 ≤ n ≤ 1e5 for all tests
 n ≤ 1000 for at least 50% tests

Example
 input
7
4 7
2 6
3 4
1 6
4 1
7 5
 output
6 4 1 7 1 4 
*/