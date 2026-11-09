class FooBar {
private:
    int n;
    condition_variable cv;
    bool fooprinted= false;
    mutex mtx;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return !fooprinted;});
        	printFoo();
            fooprinted= true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return fooprinted;});
        	printBar();
            fooprinted= false;
            cv.notify_all();
        }
    }
};