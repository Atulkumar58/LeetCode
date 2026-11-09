class Foo {
    mutex mtx;
    condition_variable cv;
    int number;
public:
    Foo() {
       number=1; 
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]{return number == 1;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        number++;
        lock.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]{return number==2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        number++;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]{return number==3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        number++;
        lock.unlock();
        cv.notify_all();
    }
};