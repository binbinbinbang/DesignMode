#pragma once
#include <iostream>

// 目标接口
class Target {
public:
    virtual void request() = 0;
};

// 被适配对象
class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee: Specific request." << std::endl;
    }
};

// 类适配器
class Adapter : public Target, private Adaptee {
    //私有继承，派生类可以访问基类的成员，但是外部不能访问基类的成员，很好的隐藏了细节。
public:
    void request() {
        std::cout << "Adapter: Adapted request." << std::endl;
        specificRequest();
    }
};

// 对象适配器
class Adapter2 : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter2(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() {
        std::cout << "Adapter2: Adapted request." << std::endl;
        adaptee->specificRequest();
    }
};

int main() {
    //私有继承方式 较优
    Target* target = new Adapter();
    target->request();

    //注入方式
    Adaptee* adaptee = new Adaptee();
    Target* target2 = new Adapter2(adaptee);
    target2->request();

    return 0;
}
