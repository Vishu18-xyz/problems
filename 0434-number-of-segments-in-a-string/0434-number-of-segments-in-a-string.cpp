class Solution {
public:
    int countSegments(string s) {

        if(s.size() == 0){
            return 0;
        }

        vector<string> v;
        string temp  = "";

        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                if(temp.size()>0){
                v.push_back(temp);
                }
                temp = "";
            }
            else{
                temp += s[i];
            }
        }

         if(temp.size()>0){
                v.push_back(temp);
           }

        return v.size();
    }
};