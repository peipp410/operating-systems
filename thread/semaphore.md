# semaphore

我们可以使用信号量作为锁和条件变量。

```c
#include<semaphore.h>
sem_t s;
sem_init(&s, 0, 1);
```

定义一个信号量s，并初始化为1。

两个关键函数：`sem_wait()`将信号量减一，如果$s<0$就等待；`sem_post()`将信号量加一，并唤醒等待的进程。

## 二值信号量（锁）

```c
sem_t m;
sem_init(&m, 0, 1);

sem_wait(&m);
//crtitical sections here
sem_post(&m);
```

进程1调用`sem_wait()`，此时m为0，因此进程1可以继续执行下面的操作。而此时若有进程2继续调用`sem_wait()`，m就变成-1，进程2无法继续后面的操作。只有等进程1调用`sem_post()`后，m重新变为0，那么进程2才可以继续执行后面的操作。

## 信号量用作条件变量

https://leetcode-cn.com/problems/print-in-order 引用题解。

```c++
#include <semaphore.h>

class Foo {
private:
    sem_t sem_1, sem_2;

public:
    Foo() {
        sem_init(&sem_1, 0, 0), sem_init(&sem_2, 0, 0);
    }

    void first(function<void()> printFirst) {
        printFirst();
        sem_post(&sem_1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&sem_1);
        printSecond();
        sem_post(&sem_2);
    }

    void third(function<void()> printThird) {
        sem_wait(&sem_2);
        printThird();
    }
};
```

用作锁时，信号量初值设为1；用作条件变量时，信号量初值设为0。