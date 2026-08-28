class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitsum = 0;
        int squaresum = 0; 

        int num = n;

        while(num>0){
            int digit = num%10;
            digitsum += digit;
            num /= 10;
        }

        while(n>0){
            int digit = n%10;
            squaresum += digit*digit;
            n /= 10;
        }

        return squaresum-digitsum >= 50;
    }

};