class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int maxelement = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]>maxelement){
                maxelement = nums[i];
            }
        }

        int right = 0;
        int left = 0;
        int count = 0;
        long long  ans = 0;

        while(right<n){
            if(nums[right] == maxelement){
                count++;
            }

            while(count>=k){
                if(nums[left] == maxelement){
                    count--;
                }
                left++;
            }
            ans+=left;
            right++;
        }

        return ans;
    }
};