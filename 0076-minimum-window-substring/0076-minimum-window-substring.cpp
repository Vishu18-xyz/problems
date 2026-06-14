class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size()<t.size()){
            return "";
        }

        int ans = INT_MAX;

        unordered_map<char,int> m;

        for(int i = 0; i<t.size(); i++){
            m[t[i]]++;
        }

        int count = m.size();
        int i = 0;
        int j = 0;
        int start = 0;

        while(j<s.size()){
            m[s[j]]--;

            if(m[s[j]] == 0){
                count--;
            }

            if(count == 0){
                while(count == 0){
                    if(ans > j-i+1){
                        ans = j-i+1;
                        start = i;
                    }
                    m[s[i]]++;
                    if(m[s[i]] > 0){
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }

        return s.substr(start,ans);

    }
};