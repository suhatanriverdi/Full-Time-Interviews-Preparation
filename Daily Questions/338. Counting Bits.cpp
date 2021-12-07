// Question Link: https://leetcode.com/problems/counting-bits/

/*
Short Explanation

When we divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. We can try to generate new range from previous, and we can see that there is a repetitive pattern between the ranges. Please check out the following and try to understand the relation between the ranges;

0 0
1 1

2 1
3 2

4 1
5 2
6 2
7 3 (For example, we can copy the values in the range 2-3, value 1 and 2 and add +1 to them which will give us 2 and 3, and get the 4-7 range)

8 1
9 2
10 2
11 3
12 2
13 3
14 3
15 4

16 1
17 2
18 2
19 3
20 2
21 3
22 3
23 4
24 2
25 3
26 3
27 4
28 3
29 4
30 4
31 5
...
*/

// O(N log N) Tme & O(N) Memory Solution
class Solution {
public:
    vector<int> countBits(int n) {
        int size = n + 1;
        vector<int> result(size, 0);
        for (int i = 0; i < size; i++) {
            result[i] = getNumOfBits(i);
        }
        return result;
    }
    
    int getNumOfBits(int n) {
        int rem, count = 0;
        while (n > 0) {
            rem = n % 2;
            count += rem;
            n >>= 1;
        }
        return count;
    }
};

// Better Recursion + Memoization Solution
class Solution {
public:
    vector<int> countBits(int n) {
        int size = n + 1;
        vector<int> result(size, 0);
        for (int i = 0; i < size; i++) {
            getNumOfBits(i, result);
        }
        return result;
    }
    
    int getNumOfBits(int n, vector<int> &memo) {
        // Memoization
        if (memo[n] != 0) {
            return memo[n];
        }
        if (n == 0) {
             return 0;
        }        
        // Store the calculated result
        memo[n] = n % 2 + getNumOfBits(n / 2, memo);
        return memo[n];
    }
};

// O(N) Time O(N) memory Solution
class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return { 0 };
        }
        int size = n + 1, prev;
        vector<int> result(size, 0);
        result[1] = 1;
        for (int i = 2; i < size; i++) {
            // If i is power of 2
            if ((i & (i - 1)) == 0) {
                prev = i;
            }
            result[i] += result[i - prev] + 1;
        }
        return result;
    }
};