class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum = INT_MIN;
        int n = nums.size();

        double sum = 0;
        int start = 0;
        int end = 0;

        while(end<n){
            sum = sum+nums[end];
            if(end-start+1 == k){;
               maxsum = max(maxsum,sum);
               sum = sum- nums[start];
               start++;
            }
            end++;
        }

        return maxsum/k;
    }
};