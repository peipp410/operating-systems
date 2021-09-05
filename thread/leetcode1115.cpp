//https://leetcode-cn.com/problems/print-foobar-alternately/submissions/
class FooBar {
private:
    int n;
    int count;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        count = 0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lck(mtx);
        for (int i = 0; i < n; i++) {
            
            while (count % 2 != 0){
                cv.wait(lck);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            count++;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lck(mtx);
        for (int i = 0; i < n; i++) {
            
            while (count % 2 == 0){
                cv.wait(lck);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            count++;
            cv.notify_one();
        }
    }
};