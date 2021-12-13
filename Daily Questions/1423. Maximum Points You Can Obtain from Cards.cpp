// Question Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> availableScores;
        availableScores.insert(availableScores.end(), cardPoints.begin() + cardPoints.size() - k, cardPoints.end());
        availableScores.insert(availableScores.end(), cardPoints.begin(), cardPoints.begin() + k);
        
        int L = 0, R = k, len = availableScores.size();
        int currentWindowSum = accumulate(availableScores.begin(), availableScores.begin() + R, 0);
        int maxScore = currentWindowSum;
        
        while (R < len) {
            currentWindowSum += availableScores[R];
            currentWindowSum -= availableScores[L];
            maxScore = max(maxScore, currentWindowSum);
            R++;
            L++;
        }
        
        return maxScore;
    }
};