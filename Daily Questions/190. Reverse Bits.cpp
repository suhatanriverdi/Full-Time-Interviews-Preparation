// Question Link: https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int k = 32, power = 31; k > 0; k--, power--) {
            int rem = n % 2;
            if (rem > 0) {
                result += pow(2, power);
            }
            n >>= 1;
        }
        return result;
    }
};