class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                int start = st.top()+1;
                int end = i;

                reverse(s.begin()+start, s.begin()+end);
                st.pop();
            }
        }

        for(int i = 0; i<n; i++){
            if(s[i] != '(' && s[i] != ')'){
                ans += s[i];
            }
        }

        return ans;

    }
};