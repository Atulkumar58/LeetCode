class Robot {
public:
    pair<int, int> pos= {0, 0};
    int maxw, maxh, circum;
    int dir= 0;
    int x[4]= {1, 0, -1, 0};
    int y[4]= {0, 1, 0, -1};

    Robot(int width, int height) {
        pos= {0, 0};
        maxh= height-1;
        maxw= width-1;
        circum= 2*(maxh+maxw);
    }
    void step(int num) {
        num%= circum;
        if(num == 0){
            if(pos.first ==0){
                if(pos.second==0) dir=3;
                if(pos.second == maxh) dir=2;
            }
            else if(pos.first == maxw){
                if(pos.second == 0) dir=0;
                if(pos.second == maxh) dir= 1;
            }
        }
        while(num){
            pos= {pos.first+x[dir]*num, pos.second+y[dir]*num};
            num=0;
            if(pos.first < 0){
                num= 0- pos.first;
                pos.first= 0;
                dir= (dir+1)%4;
            }else if(pos.second < 0){
                num = 0-pos.second;
                pos.second=0;
                dir= (dir+1)%4;
            }else if(pos.first > maxw){
                num= pos.first- maxw;
                pos.first= maxw;
                dir= (dir+1)%4;
            }else if(pos.second > maxh){
                num= pos.second - maxh;
                pos.second = maxh;
                dir= (dir+1)%4;
            } 
            // cout<<pos.first <<" "<<pos.second<<" " << num<<endl;
        }
        // cout<<endl;
    }

    vector<int> getPos() {
        return {pos.first, pos.second};
    }
    string getDir() {
        switch(dir){
            case 0: return "East";
            case 1: return "North";
            case 2: return "West";
            case 3: return "South";
        }
        return " ";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */