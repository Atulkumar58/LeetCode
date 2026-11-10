class DiningPhilosophers {
    condition_variable cv;
    mutex mtx;
    vector<bool> fork;
public:
    DiningPhilosophers() {
        fork.resize(5, 1);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{return fork[philosopher] && fork[(philosopher+1)%5]; });
        fork[philosopher]=0;
        fork[(philosopher+1)%5]=0;
        lock.unlock();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        lock.lock();
        fork[philosopher]= fork[(philosopher+1)%5]=1;
        lock.unlock();
        cv.notify_all();
    }
};