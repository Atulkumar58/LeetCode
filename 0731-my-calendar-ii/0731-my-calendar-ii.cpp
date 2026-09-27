class MyCalendarTwo {
public:
    vector<vector<int>> bookings;
    MyCalendarTwo() {
        
    }
    bool book(int startTime, int endTime) {
        bool possible= true;
        for(auto& i: bookings){
            if(max(i[0], startTime) < min(i[1], endTime)){
                if(i[2] == 2){
                    return false;
                }
            }

        }

        sort(bookings.begin(), bookings.end());
        vector<vector<int>> temp;
        int last= startTime;
        for(auto& i: bookings){
            if(max(i[0], startTime) < min(i[1], endTime)){
                if(last < i[0]){
                    temp.push_back({last, i[0], 1});
                    last= i[0];
                }
                if(last > i[0]){
                    temp.push_back({i[0], last, i[2]});
                    i[0]=last;
                }

                int l= last;
                int r= min(i[1], endTime);

                if(i[1] > endTime){
                    temp.push_back({endTime, i[1], i[2]});
                    i[1]=endTime;
                }

                i={l, r, i[2]+1};
                last= r;
            }
        }

        if(last < endTime){
            temp.push_back({last, endTime, 1});
        }
        for(auto &i: temp){
            bookings.push_back(i);
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */