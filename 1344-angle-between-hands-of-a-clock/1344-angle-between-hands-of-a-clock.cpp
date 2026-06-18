class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minutangle = minutes*6;
        double hourangle = 30*(hour%12)+(0.5*minutes);

        double angle = abs(hourangle-minutangle);

        return min(angle,360-angle);
        
    }
};