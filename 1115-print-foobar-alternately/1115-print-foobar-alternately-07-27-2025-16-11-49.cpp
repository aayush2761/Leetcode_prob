// since both thread can access the function same time and can print it in same time so it will be a critical sections 
// now we can use a mutex / locks to provide the mutual exclusions 
// since ther is ordering so we have to use something as constional varilable 
// conditional variable can be implemented using the function signal and wait functionality 

// ************************************************************************************************************************//



class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool isFooPrinted;

public:
    FooBar(int n) {
        this->n = n;
        isFooPrinted= false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
        	// printFoo() outputs "foo". Do not change or remove this line.
            cv.wait(lock, [this] {return !isFooPrinted;});
        	printFoo();
            isFooPrinted= true;
            // condtional variable
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            // access 
            cv.wait(lock, [this] {return isFooPrinted;});
        	// printBar() outputs "bar". Do not change or remove this line.
            printBar();
            isFooPrinted= false;
             cv.notify_one();
        }
    }
};