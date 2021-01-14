/*
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n.
  Each client i requests d[i] packages.
  Each client is visited exactly by one route
Total number of packages requested by clients of each truck cannot exceed its capacity
  Each truck must visit at least one client
=>>Goal
   Compute number R of solutions
   Note that: the orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
**Input
  Line 1: n,K,Q (2≤n≤10,1≤K≤5,1≤Q≤20)
  Line 2: d[1],...,d[n] (1≤d[i]≤10)
**Output
R mod 10^9+7
TEST
3 2 4
3 2 1
=> 4
There are 4 solutions
 route[1] = 0 -> 1 -> 0 and route[2] = 0 -> 2 -> 3 -> 0
 route[1] = 0 -> 1 -> 3 -> 0 and route[2] = 0 -> 2 -> 0
 route[1] = 0 -> 1 -> 0 and route[2] = 0 -> 3 -> 2 -> 0
 route[1] = 0 -> 2 -> 0 and route[2]= 0 -> 3 -> 1 -> 0
---------------------------------------------------------
*/
