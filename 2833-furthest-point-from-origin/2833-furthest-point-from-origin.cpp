class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0;
        int l = 0;
        int ans = 0;
        int n = moves.size();

        for (int i = 0; i<n; i++){
            if(moves[i] == 'L'){
                l++;
            }
            else if(moves[i] == 'R'){
                r++;
            }
            else{
                continue;
            }
        }

        for(int i = 0; i<n; i++){
            if(moves[i] == 'L'){
                ans = ans-1;
            }

            else if(moves[i] == 'R'){
                ans = ans+1;
            }

            else{
                if(l>r){
                    ans = ans-1;
                }
                else{
                    ans = ans+1;
                }
            }
        }

        return abs(ans);

        
    }
};