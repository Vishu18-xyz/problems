class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int totalsum = 0;
        for (int i = 0; i<n; i++){
            totalsum += cardPoints[i];
        } 

        int size = n - k;

        int left = 0;
        int right = 0;

        int sum = 0;

        while (right<size) {
            sum += cardPoints[right];
            right++;
        }

        int minsum = sum;

        while (right<n) {
            sum += cardPoints[right];
            sum -= cardPoints[left];
            left++;
            right++;
            minsum = min(minsum,sum);
        }

        return totalsum-minsum;
    }
};