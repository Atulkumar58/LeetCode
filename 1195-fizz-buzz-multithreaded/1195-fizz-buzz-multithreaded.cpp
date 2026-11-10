class FizzBuzz {
private:
    int n;
    int counter=1;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return counter > n || (counter%3==0 && counter%5!=0);});

            if(counter > n) break;

            printFizz();
            counter++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return counter > n || (counter%3!=0 && counter%5==0);});

            if(counter > n) break;

            printBuzz();
            counter++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return counter > n || (counter%3==0 && counter%5==0);});

            if(counter > n) break;

            printFizzBuzz();
            counter++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return counter > n || (counter%3!=0 && counter%5!=0);});

            if(counter > n) break;

            printNumber(counter);
            counter++;
            cv.notify_all();
        }
    }
};