#include "../exercise.h"

struct A {
    static int num_a;  // 静态成员声明

    A() {
        ++num_a;
    }
    virtual ~A() {  // 虚析构函数确保多态析构
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};
int A::num_a = 0;  // 类外定义并初始化静态成员

struct B final : public A {
    static int num_b;  // 静态成员声明

    B() {
        ++num_b;
    }
    ~B() override {  // 正确覆盖析构函数
        --num_b;
    }

    char name() const final override {
        return 'B';
    }
};
int B::num_b = 0;  // 类外定义并初始化静态成员

int main(int argc, char **argv) {
    auto a = new A;
    auto b = new B;
    ASSERT(A::num_a == 2, "A::num_a should be 2");  // A构造和B继承的A构造各+1
    ASSERT(B::num_b == 1, "B::num_b should be 1");
    ASSERT(a->name() == 'A', "a->name() should be 'A'");
    ASSERT(b->name() == 'B', "b->name() should be 'B'");

    delete a;
    delete b;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    A *ab = new B;
    ASSERT(A::num_a == 1, "A::num_a should be 1 (from B)");
    ASSERT(B::num_b == 1, "B::num_b should be 1");
    ASSERT(ab->name() == 'B', "ab->name() should be 'B' (dynamic binding)");

    // 安全的向下转型
    B &bb = dynamic_cast<B &>(*ab);
    ASSERT(bb.name() == 'B', "bb.name() should be 'B'");

    delete ab;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    return 0;
}
