class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();

        int ans = 0;
        int first = 0;
        int second = 0;
        int vowelcount = 0;

        while(second<n){
            if(s[second] == 'a' || s[second] == 'e' || s[second] == 'i' || s[second] == 'o' || s[second] == 'u' ){
                vowelcount++;
            }

            if((second-first+1) == k){
                ans = max(ans,vowelcount);
                if(s[first] == 'a' || s[first] == 'e' || s[first] == 'i' || s[first] == 'o' || s[first] == 'u'){
                    vowelcount--;
                }
                first++;
            }
            second++;
        }

        return ans;
    }
};