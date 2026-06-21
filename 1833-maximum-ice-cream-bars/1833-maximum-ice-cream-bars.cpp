class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int icecream = 0;
        int i = 0;

        while(i<n && coins>= costs[i]){
            if(coins>=costs[i]){
               coins = coins-costs[i];
               icecream++;
               i++;
            }
        }
        return icecream;
    }
};