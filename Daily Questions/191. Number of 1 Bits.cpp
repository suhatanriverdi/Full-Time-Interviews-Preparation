// Question Link: https://leetcode.com/problems/number-of-1-bits/

// O(32) Time & O(1) Memory Solution
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0, rem;
        while (n > 0) {
            rem = n % 2;
            n >>= 1;
            if (rem > 0) {
                count++;
            }
        }
        return count;
    }
};

// Slightly Better Solution
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0, rem;
        while (n > 0) {
            rem = n % 2;
            n >>= 1;
            count += rem;
        }
        return count;
    }
};