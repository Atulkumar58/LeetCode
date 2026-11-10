class H2O {
    mutex mtx;
    condition_variable cv;
    int counter; //{-2, 2}
public:
    H2O() {
        counter = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]{return counter!= 2;});
        counter++;
        lock.unlock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        cv.notify_all();
        
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] {return counter>=0;});
        counter-=2;
        lock.unlock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        cv.notify_all();
    }
};