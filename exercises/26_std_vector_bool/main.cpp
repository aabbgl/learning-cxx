﻿#include "../exercise.h"
#include <vector>

int main(int argc, char **argv) {
    std::vector<bool> vec(100, true);
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");

    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    ASSERT(sizeof(vec) == 40, "Fill in the correct value.");

    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value.");
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`");
        ref = false;  // 修改代理对象
        ASSERT(!ref, "Fill in `ref` or `!ref`");
        // 需要将修改显式写回vector
        vec[30] = ref;  // 新增这行
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); // 现在应该检查false
    }
    return 0;
}
