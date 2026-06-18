class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = hour + (double)minutes / 60;
        double b= (double)minutes / 5;
        a= abs(a-b) * 360 / 12;
        return min(a, 360-a);
    }
};