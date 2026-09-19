class Solution {
public:
    double calcdistance(int x, int y, int a, int b){
        return sqrt(double (pow(x-a, 2)+ pow(y-b, 2)));
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //Hamming distance
        if(abs(xCenter- x1) <= radius && yCenter<=y2 && yCenter>=y1) return 1;
        if(abs(xCenter- x2) <= radius && yCenter<=y2 && yCenter>=y1) return 1;
        if(abs(yCenter- y1) <= radius && xCenter<=x2 && xCenter>=x1) return 1;
        if(abs(yCenter- y2) <= radius && xCenter<=x2 && xCenter>=x1) return 1;

        if(calcdistance(xCenter, yCenter, x1, y1) <= radius) return 1;
        if(calcdistance(xCenter, yCenter, x2, y2) <= radius) return 1;
        if(calcdistance(xCenter, yCenter, x1, y2) <= radius) return 1;
        if(calcdistance(xCenter, yCenter, x2, y1) <= radius) return 1;

        if(xCenter <= x2 && xCenter >= x1 && yCenter >= y1 && yCenter<= y2) return 1;
        return false;
    }
};