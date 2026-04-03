class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> temp;
        for(int i =0; i<n; i++){
            if(nums[i]>=0){
                temp.push_back(nums[i]);
            }
        }
            int m = temp.size();

            k = k%m;
            vector<int> temp2(m);
            for(int i = 0; i<m; i++){
                temp2[(i-k+m)%m] = temp[i];
            }

            int j = 0; 
            for(int i = 0; i<n; i++){
                if(nums[i]>=0){
                  nums[i] = temp2[j];
                  j++;
                }
            }

            return nums;
    }
};