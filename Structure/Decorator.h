#pragma once

#include <iostream>

// 抽象组件,被装饰对象
class Component {
public:
    virtual void operation() = 0;
};

// 具体组件
class ConcreteComponent : public Component {
public:
    void operation() {
        std::cout << "ConcreteComponent: Operation." << std::endl;
    }
};

// 抽象装饰器
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* comp) : component(comp) {}

    void operation() {
        component->operation();
    }
};

// 具体装饰器 A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

    void operation() {
        Decorator::operation();
        std::cout << "ConcreteDecoratorA: Additional operation A." << std::endl;
    }
};

// 具体装饰器 B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}

    void operation() {
        Decorator::operation();
        std::cout << "ConcreteDecoratorB: Additional operation B." << std::endl;
    }
};

int main() {
    Component* component = new ConcreteComponent();
    component->operation();

    Component* decoratedComponentA = new ConcreteDecoratorA(component);
    decoratedComponentA->operation();

    Component* decoratedComponentB = new ConcreteDecoratorB(decoratedComponentA);
    decoratedComponentB->operation();

    return 0;
}
/*输出：
ConcreteComponent: Operation.
ConcreteComponent : Operation.
ConcreteDecoratorA : Additional operation A.
ConcreteComponent : Operation.
ConcreteDecoratorA : Additional operation A.
ConcreteDecoratorB : Additional operation B.
*/
/*结论：
可以看到，装饰模式通过装饰器类的嵌套组合，动态地为对象添加新的行为，而不需要改变其原始类结构。
这样可以实现功能的动态组合和扩展，同时保持代码的灵活性和可维护性。
*/