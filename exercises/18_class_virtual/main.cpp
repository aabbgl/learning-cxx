#include "../exercise.h"

struct A {
    virtual char virtual_name() const {
        return 'A';
    }
    char direct_name() const {
        return 'A';
    }
};

struct B : public A {
    char virtual_name() const override {
        return 'B';
    }
    char direct_name() const {
        return 'B';
    }
};

struct C : public B {
    char virtual_name() const final {
        return 'C';
    }
    char direct_name() const {
        return 'C';
    }
};

struct D : public C {
    char direct_name() const {
        return 'D';
    }
};

int main(int argc, char **argv) {
    constexpr auto MSG = "Replace '?' with its correct name.";

    A a;
    B b;
    C c;
    D d;

    // 直接调用成员函数
    ASSERT(a.virtual_name() == 'A', MSG);
    ASSERT(b.virtual_name() == 'B', MSG);
    ASSERT(c.virtual_name() == 'C', MSG);
    ASSERT(d.virtual_name() == 'C', MSG); // D 没有重写 virtual_name()
    ASSERT(a.direct_name() == 'A', MSG);
    ASSERT(b.direct_name() == 'B', MSG);
    ASSERT(c.direct_name() == 'C', MSG);
    ASSERT(d.direct_name() == 'D', MSG);

    A &rab = b;
    B &rbc = c;
    C &rcd = d;

    // 通过引用调用虚函数和非虚函数
    ASSERT(rab.virtual_name() == 'B', MSG);  // 虚函数动态绑定到 B
    ASSERT(rbc.virtual_name() == 'C', MSG);  // 虚函数动态绑定到 C
    ASSERT(rcd.virtual_name() == 'C', MSG);  // 虚函数动态绑定到 C
    ASSERT(rab.direct_name() == 'A', MSG);   // 非虚函数，静态绑定为 A
    ASSERT(rbc.direct_name() == 'B', MSG);   // 非虚函数，静态绑定为 B
    ASSERT(rcd.direct_name() == 'C', MSG);   // 非虚函数，静态绑定为 C

    A &rac = c;
    B &rbd = d;

    ASSERT(rac.virtual_name() == 'C', MSG);  // 虚函数动态绑定到 C
    ASSERT(rbd.virtual_name() == 'C', MSG);  // D 继承自 C，virtual_name() 是 final 的 C
    ASSERT(rac.direct_name() == 'A', MSG);   // 静态绑定为 A
    ASSERT(rbd.direct_name() == 'B', MSG);   // 静态绑定为 B

    A &rad = d;

    ASSERT(rad.virtual_name() == 'C', MSG);  // D 的虚函数调用绑定到继承链中最深的 virtual_name() 即 C
    ASSERT(rad.direct_name() == 'A', MSG);   // 静态绑定为 A

    return 0;
}

// READ: 扩展阅读-纯虚、抽象 <https://zh.cppreference.com/w/cpp/language/abstract_class>
// READ: 扩展阅读-虚继承 <https://zh.cppreference.com/w/cpp/language/derived_class>
