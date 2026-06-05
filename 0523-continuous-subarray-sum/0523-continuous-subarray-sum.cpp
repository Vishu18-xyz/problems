class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        m[0] = -1;
        int prefix = 0;

        for(int i = 0; i<n; i++){
           prefix += nums[i];
           int rem = prefix % k;

           if(m.count(rem)){
              if(i-m[rem] >= 2){
                return true;
              }
           }
           else{
                m[rem] = i;
            }
        }
        return false;
    }
};