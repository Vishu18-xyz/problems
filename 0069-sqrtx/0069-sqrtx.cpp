class Solution {
public:
    int mySqrt(int x) {
        int root = 0;

        int start = 1;
        int end = x;

        while(start <= end){
            long long mid = start + (end-start)/2;

            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid > x){
                
                end = mid-1;
            }
            else{
                root = mid;
                start = mid+1;
            }
        } 

        return root;
    }
};