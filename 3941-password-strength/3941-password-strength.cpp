class Solution {
public:
    int passwordStrength(string password) {
        set<int> s;
        int n = password.size();
        int strength =0;

        for(int i = 0; i<n; i++){
            s.insert(password[i]);
        }


        int m = s.size();

        for(auto it = s.begin(); it != s.end(); it++) {
            if(*it>='a' && *it<='z'){
                strength += 1;
            }
            else if(*it>='A' && *it<='Z'){
                strength += 2; 
            }
            else if(*it>='0' && *it<='9'){
                strength += 3;
            }
            else{
                strength += 5;
            }
        }

        return strength;
    }
};