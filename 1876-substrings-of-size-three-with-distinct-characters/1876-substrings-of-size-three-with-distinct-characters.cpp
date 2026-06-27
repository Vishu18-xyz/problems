class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int first = 0;
        int second = 0;
        unordered_map<char,int> mp;
        int count = 0;

        while(second<n){
            mp[s[second]]++;

            if(second-first+1<3){
                second++;
            }
            else if(mp.size() == 3){
                count++;
                mp.erase(s[first]);
                first++;
                second++;
            }
            else{
                mp[s[first]]--;
                if(mp[s[first]] == 0){
                    mp.erase(s[first]);
                }
                first++;
                second++;
            }


        }
        return count;

    }
};