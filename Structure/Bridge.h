#pragma once
#include <iostream>

//����ģʽ�������ߺ�ʵ���߷ֿ����룬Ȼ����ݳ�������ʱ��ϡ�ʹ�õ��Ƿ������ϵ�˼�롣�������������
// ʵ����ӿ�
class Implementor {
public:
    virtual void operationImpl() = 0;
};

// ����ʵ���� A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() {
        std::cout << "ConcreteImplementorA: Operation implementation A." << std::endl;
    }
};

// ����ʵ���� B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() {
        std::cout << "ConcreteImplementorB: Operation implementation B." << std::endl;
    }
};

// ������
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void operation() = 0;
};

// ��չ������ A
class RefinedAbstractionA : public Abstraction {
public:
    RefinedAbstractionA(Implementor* impl) : Abstraction(impl) {}

    void operation() {
        std::cout << "RefinedAbstractionA: Operation in progress." << std::endl;
        implementor->operationImpl();
    }
};

// ��չ������ B
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
