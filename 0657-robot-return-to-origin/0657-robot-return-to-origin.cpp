class Solution {
public:
    bool judgeCircle(string moves) {
        int r = 0;
        int l = 0;
        int u = 0;
        int d = 0;

        int n = moves.size();

        for(int i =0; i<n; i++){
            if(moves[i] == 'U'){
                u++;
            }
            else if(moves[i] == 'D'){
                d++;
            }
            else if(moves[i]=='L'){
                l++;
            }
            else{
                r++;
            }
        }

        if(l==r && u==d){
            return 1;
        }
        else{
            return 0;
        }
    }
};