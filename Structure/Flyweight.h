#pragma once
#include <iostream>
#include <unordered_map>
//共享细粒度的对象，不用重复创建对象，提高系统性能。
// 享元接口
class Flyweight {
public:
    virtual void operation(int extrinsicState) = 0;
};

// 具体享元类
class ConcreteFlyweight : public Flyweight {
private:
    int intrinsicState; // 内部状态

public:
    ConcreteFlyweight(int intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(int extrinsicState) {
        std::cout << "ConcreteFlyweight: Intrinsic State = " << intrinsicState;
        std::cout << ", Extrinsic State = " << extrinsicState << std::endl;
    }
};

// 享元工厂类
class FlyweightFactory {
private:
    std::unordered_map<int, Flyweight*> flyweights; // 享元池，可以用做线程池，数据库连接池

public:
    Flyweight* getFlyweight(int key) {
        if (flyweights.find(key) != flyweights.end()) {
            // 如果享元池中已存在对应的享元对象，则直接返回
            return flyweights[key];
        }
        else {
            // 如果享元池中不存在对应的享元对象，则创建新的享元对象并存储到享元池中
            Flyweight* flyweight = new ConcreteFlyweight(key);
            flyweights[key] = flyweight;
            return flyweight;
        }
    }
};

int main() {
    FlyweightFactory factory;

    // 第一次获取享元对象，将会创建新的享元对象
    Flyweight* flyweight1 = factory.getFlyweight(1);
    flyweight1->operation(100);

    // 再次获取相同的享元对象，将会直接使用已存在的享元对象
    Flyweight* flyweight2 = factory.getFlyweight(1);
    flyweight2->operation(200);

    // 获取不同的享元对象
    Flyweight* flyweight3 = factory.getFlyweight(2);
    flyweight3->operation(300);

    return 0;
}
/*
输出：
ConcreteFlyweight: Intrinsic State = 1, Extrinsic State = 100
ConcreteFlyweight: Intrinsic State = 1, Extrinsic State = 200
ConcreteFlyweight: Intrinsic State = 2, Extrinsic State = 300
*/
/*
结论：
可以看到，通过共享享元对象，我们可以节省内存空间，并且在需要时重用已创建的对象，提高系统性能。
享元模式适用于需要创建大量细粒度对象，并且这些对象之间有许多共同的属性和行为的情况。
*/