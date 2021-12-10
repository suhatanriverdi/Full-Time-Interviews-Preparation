// Question Link: https://leetcode.com/problems/mirror-reflection/

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = std::lcm(p, q);
        int numOfBouncing = lcm / q;
        if (numOfBouncing % 2 == 0) {
            return 2;
        }
        int numOfBoxes = (lcm / p) % 2;
        return numOfBoxes;
    }
};