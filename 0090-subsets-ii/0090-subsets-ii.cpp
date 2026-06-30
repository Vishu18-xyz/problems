class Solution {
public:
    void subs(vector<int>&arr, vector<int>&temp,vector<vector<int>>&ans , int index){
        ans.push_back(temp);

        for(int i = index ; i<arr.size(); i++){
            if(i>index && arr[i-1]==arr[i]){
                continue;
            }

            temp.push_back(arr[i]);
            subs(arr, temp, ans, i+ 1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        subs(nums, temp, ans, 0);

        return ans;
    }
};