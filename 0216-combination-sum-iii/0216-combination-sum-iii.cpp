class Solution {
public:
    void ways (int n , int k ,int num , vector<int> temp, vector<vector<int>> &combinations){
        if(k == 0) {
        if(n == 0) {
            combinations.push_back(temp);
        }
        return;
    }
        if(n<0 || num == 0){
            return;
        }

        temp.push_back(num);
        ways(n-num,k-1,num-1,temp,combinations);
        temp.pop_back();
        ways(n, k,num-1,temp,combinations);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> temp;
        ways(n,k,9,temp,combinations);
        return combinations;
    }
};