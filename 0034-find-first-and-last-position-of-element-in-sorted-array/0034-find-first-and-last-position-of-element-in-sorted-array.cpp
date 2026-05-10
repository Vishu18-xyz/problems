class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        int s=0;
        int e = n-1;
        int mid = s+ (e-s)/2;
        int ans1= -1;
        vector<int> ans3;
        while(s<=e){
            if(nums[mid]==target){
                ans1 = mid;
                e=mid-1;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
            else if (target<nums[mid]){
                e=mid-1;
            }
             mid = s + (e-s)/2;
        }
        ans3.push_back(ans1);

        int ans2= -1;
        int s1=0;
        int e1=n-1;
        int mid1 = s1 + (e1-s1)/2;

        while(s1<=e1){
            if(nums[mid1]==target){
                ans2=mid1;
                s1=mid1+1;
            }
            else if(target>nums[mid1]){
                s1=mid1+1;
            }
            else if( target< nums[mid1]){
                e1=mid1-1;
            }
            mid1 = s1 + (e1-s1)/2;
        }
        ans3.push_back(ans2);

        return ans3;

    }
};