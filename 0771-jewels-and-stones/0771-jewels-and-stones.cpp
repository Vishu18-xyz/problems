class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mp;
        int n = jewels.size();

        for(int i = 0; i<n; i++){
            mp[jewels[i]]++;
        }

        int count = 0;

        for(int i = 0; i<stones.size();i++){
            if(mp[stones[i]] == 1){
                count++;
            }
        }

        return count;

        
    }
};