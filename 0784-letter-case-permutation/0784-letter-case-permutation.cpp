class Solution {
public:
    
    void permut(string s, int index, string &temp, vector<string> &ans){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }

       if(s[index] >= '0' && s[index]<= '9'){
           temp.push_back(s[index]);
           permut(s,index+1,temp,ans);
           temp.pop_back();
       }

       else{
           temp.push_back(tolower(s[index]));
           permut(s,index+1,temp,ans);

           temp.pop_back();

           temp.push_back(toupper(s[index]));
           permut(s,index+1,temp,ans);
           temp.pop_back();
       }
    }

    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> ans;

        string temp = "";

        permut(s,0,temp,ans);
        return ans;
    }
};