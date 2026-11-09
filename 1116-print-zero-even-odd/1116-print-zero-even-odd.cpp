class ZeroEvenOdd {
private:
    int n;
    int count;
    mutex mtx;
    condition_variable cv;
    bool z;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        count =1;
        z= true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return z || count > n;});
            if(count >n) break;

            printNumber(0);
            z = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return  count > n || (!z && count%2==0);});
            if(count > n) break;
            printNumber(count);
            z= true;
            count++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(count <= n){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return count > n || (!z && count%2==1);});
            if(count > n) break;
            printNumber(count);
            z= true;
            count++;
            cv.notify_all();
        }
    }
};