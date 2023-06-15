#pragma once
#include <iostream>

//桥梁模式。操作者和实现者分开编译，然后根据场景运行时组合。使用的是分离和组合的思想。减少类的增长。
// 实现类接口
class Implementor {
public:
    virtual void operationImpl() = 0;
};

// 具体实现类 A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() {
        std::cout << "ConcreteImplementorA: Operation implementation A." << std::endl;
    }
};

// 具体实现类 B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() {
        std::cout << "ConcreteImplementorB: Operation implementation B." << std::endl;
    }
};

// 抽象类
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void operation() = 0;
};

// 扩展抽象类 A
class RefinedAbstractionA : public Abstraction {
public:
    RefinedAbstractionA(Implementor* impl) : Abstraction(impl) {}

    void operation() {
        std::cout << "RefinedAbstractionA: Operation in progress." << std::endl;
        implementor->operationImpl();
    }
};

// 扩展抽象类 B
class RefinedAbstractionB : public Abstraction {
public:
    RefinedAbstractionB(Implementor* impl) : Abstraction(impl) {}

    void operation() {
        std::cout << "RefinedAbstractionB: Operation in progress." << std::endl;
        implementor->operationImpl();
    }
};

int main() {
    Implementor* implA = new ConcreteImplementorA();
    Abstraction* absA = new RefinedAbstractionA(implA);
    absA->operation();

    Implementor* implB = new ConcreteImplementorB();
    Abstraction* absB = new RefinedAbstractionB(implB);
    absB->operation();

    return 0;
}
