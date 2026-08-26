class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        set<int> s;

        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
            s.insert(nums[i]);
        }

        int ans = 0;

        for(auto x : s){
            if(k == 0){
                if(mp[x] > 1){
                    ans++;
                }
            }

            else{
                if(mp.find(x + k) != mp.end()){
                    ans ++;
                }
            }
        }

        return ans;
    }
};