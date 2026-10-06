class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.size();
        int count = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }

            else{
                if(st.empty()){
                    count++;
                }

                else{
                    st.pop();
                }
              
            }
        }

        return count + st.size();
    }
};