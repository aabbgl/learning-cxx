#include "../exercise.h"

// 通用加法模板
template <typename T>
T plus(T a, T b) {
    return a + b;
}

int main(int argc, char **argv) {
    // 整数测试
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    // 精确浮点数测试
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");

    // 浮点数近似比较
    double result = plus(0.1, 0.2);
    ASSERT((result > 0.3 - 1e-10 && result < 0.3 + 1e-10),
           "Approximate comparison for 0.1 + 0.2");

    return 0;
}
