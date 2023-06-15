#pragma once
#include <iostream>
//代理模式的优点包括：
//
//可以对客户端隐藏真实主题的具体实现，提供了一种间接访问的方式。
//可以在访问真实主题之前或之后添加额外的逻辑，例如权限验证、缓存等。
//可以对真实主题的方法进行控制，例如限制方法的调用次数、延迟加载等。
//代理模式的缺点包括：
//
//由于引入了代理对象，可能会增加系统的复杂性。
//可能会影响系统的性能，因为代理需要处理额外的操作。
//代理模式适用于以下情况：
//
//需要控制对一个对象的访问，并在访问前后执行额外的操作。
//需要对原始对象进行包装，以提供额外的功能或修改原始对象的行为。
//需要通过引入中间层来简化客户端与真实对象之间的交互。
//总结起来，代理模式通过引入一个代理对象来控制对另一个对象的访问，从而实现对真实对象的间接访问和控制。它提供了一种灵活的方式来添加额外的功能，同时也可以隐藏真实对象的具体实现。


// 抽象主题
class Subject {
public:
    virtual void request() = 0;
};

// 真实主题
class RealSubject : public Subject {
public:
    void request() {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// 代理主题
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    void request() {
        if (realSubject == nullptr) {
            realSubject = new RealSubject();
        }

        // 控制和增强真实主题的方法调用
        std::cout << "Proxy: Pre-processing request." << std::endl;
        realSubject->request();
        std::cout << "Proxy: Post-processing request." << std::endl;
    }
};

int main() {
    Proxy proxy;
    proxy.request();

    return 0;
}
