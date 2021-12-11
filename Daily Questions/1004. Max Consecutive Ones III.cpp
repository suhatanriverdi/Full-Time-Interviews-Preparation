// Question Link: https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size(), longestWindowLen = 0, currentWindowLen = 0, numOfZeros = 0;
        // Sliding Window
        deque<int> deck;
        for (int i = 0; i < len; i++) {
            // Push whatever comes in to the deque in any way, then we'll handle the cases
            deck.push_back(nums[i]);
            // Update "numOfzeros" according to the "k"
            if (nums[i] == 0) {
                numOfZeros++;
                // Pop the elements untill "numOfZeros < k"
                while (numOfZeros > k) {
                    numOfZeros -= (deck.front() == 0) ? 1 : 0;
                    deck.pop_front();
                }
            }
            // Update the longest window length
            currentWindowLen = deck.size();
            longestWindowLen = max(longestWindowLen, currentWindowLen);
        }
        return longestWindowLen;
    }
};