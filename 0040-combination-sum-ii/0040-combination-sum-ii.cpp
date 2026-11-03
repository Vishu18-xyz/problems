class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int index, int target, vector<int>& temp) {

        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(index == candidates.size() || target < 0) {
            return;
        }

        for(int i = index; i < candidates.size(); i++) {

            if(i > index && candidates[i] == candidates[i-1]) {
                continue;
            }

            if(candidates[i] > target) {
                break;
            }

            temp.push_back(candidates[i]);

            solve(candidates, i+1, target-candidates[i], temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> temp;

        solve(candidates, 0, target, temp);

        return ans;
    }
};