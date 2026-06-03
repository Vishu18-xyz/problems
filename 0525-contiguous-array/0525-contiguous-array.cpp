class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }

        int maxlen = 0; 
        int prefix = 0;
        mp[0] = -1;

        for(int i = 0; i<n; i++){
            prefix += nums[i];

            if(mp.count(prefix)){
                maxlen = max(maxlen,i-mp[prefix]);
            }
            else{
                mp[prefix] = i;
            }
        }

        return maxlen;


    }
};