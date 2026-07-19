class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool>visited(26,0);
        vector<int> lastseen(26);
        stack<char> st;
        string result = "";

        for(int i = 0; i<n; i++){
            lastseen[s[i]-'a'] = i;
        }

        int i = 0;

        while(i<n){
            char ch = s[i];
            if(st.empty()){ 
            st.push(ch);
            visited[ch-'a']=1;
            }

            if(visited[ch-'a']){
                i++;
                continue;
            }
            else{
                while(!st.empty() && st.top()>ch && lastseen[st.top()-'a'] > i){
                    char removed = st.top();
                    st.pop();
                    visited[removed-'a'] = 0;
                }
                st.push(ch);
                visited[ch-'a']=1;   
            }
            i++;
        }
        while(!st.empty()){
            result+= st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());

        return result;
    }
};