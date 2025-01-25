#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

// TODO: 实现正确的缓存优化斐波那契计算

static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 从已缓存位置开始计算到目标索引
    for (int j = cache.cached; j <= i; ++j) {
        cache.cache[j] = cache.cache[j-1] + cache.cache[j-2];
    }
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // 初始化缓存结构体（前两个斐波那契数+已缓存计数）
    FibonacciCache fib{{0, 1}, 2}; // cache[0]=0, cache[1]=1, cached=2

    // 测试并输出结果
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}

