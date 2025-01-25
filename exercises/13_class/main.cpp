#include "../exercise.h"

// C++ 中，`class` 和 `struct` 之间的**唯一区别**是
// `class` 默认访问控制符是 `private`，
// `struct` 默认访问控制符是 `public`。
// READ: 访问说明符 <https://zh.cppreference.com/w/cpp/language/access>

// 这个 class 中的字段被 private 修饰，只能在 class 内部访问。

class Fibonacci {
    size_t cache[16];
    int cached;

public:
    // 构造函数初始化前两个斐波那契数和缓存计数器
    Fibonacci() : cache{0, 1}, cached(2) {}

    // 缓存优化的斐波那契计算
    size_t get(int i) {
        // 使用 while 循环确保完整计算
        while (cached <= i) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
            ++cached;
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci fib; // 自动调用构造函数初始化
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}

