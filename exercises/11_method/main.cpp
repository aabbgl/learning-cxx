#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // 构造函数初始化前两个斐波那契数和缓存计数
    Fibonacci() : cache{0, 1}, cached(2) {}

    // 缓存优化的斐波那契计算
    unsigned long long get(int i) {
        // 从已缓存位置继续计算
        while (cached <= i) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
            ++cached;
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci fib; // 自动调用构造函数初始化

    // 验证斐波那契数列第10项
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;

    return 0;
}
