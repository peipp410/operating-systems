//https://leetcode-cn.com/problems/print-in-order/
class Foo {
public:
    int k = 1;
    mutex mtx;
    condition_variable cv;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lk(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        k = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(mtx);
        // printSecond() outputs "second". Do not change or remove this line.
        while (k != 2) cv.wait(lk);
        printSecond();
        k = 3;
        cv.notify_all();
   }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(mtx);
        // printThird() outputs "third". Do not change or remove this line.
        while (k != 3) cv.wait(lk);
        printThird();
    }
};