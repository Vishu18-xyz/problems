class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        int total = 0;
        int rem;

        for(int i = 0; i<n; i++){
            prefix += nums[i];
            rem = prefix % k;

            if(rem<0){// if our rmainder is negative , make it positive 
                rem = k+rem;
            }

            if(m.count(rem)){
                total += m[rem];
                m[rem]++;
            }
            else{
                m[rem] = 1;
            }

        }
        return total;

    }
};