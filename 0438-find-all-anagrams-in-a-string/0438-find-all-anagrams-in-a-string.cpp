class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> ans;
        vector<int> freq(26,0);
        vector<int> window(26,0);

        if(n<m){
            return ans;
        }

        for(int i = 0; i<m; i++){
            freq[p[i]-'a']++;
            window[s[i]-'a']++;
        }

        if(window == freq){
            ans.push_back(0);
        }

        int left = 0;
        int right = p.size()-1; 

        while(right+1 < n){
            window[s[left]-'a']--;
            left++;
            right++;
            window[s[right]-'a']++;

            if(freq == window){
                ans.push_back(left);
            }
        }

        return ans;
    }
};