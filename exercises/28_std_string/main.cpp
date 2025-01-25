#include "../exercise.h"
#include <string>

int main(int argc, char **argv) {
    using namespace std::string_literals;
    auto hello = "Hello"s;  // 使用s后缀创建std::string
    auto world = "world";   // 普通字符串字面量（const char[6]）

    // 检查类型
    ASSERT((std::is_same_v<decltype(hello), std::string>), "Fill in the missing type.");
    ASSERT((std::is_same_v<decltype(world), const char*>), "Fill in the missing type.");

    // 拼接字符串
    ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string.");

    return 0;
}
