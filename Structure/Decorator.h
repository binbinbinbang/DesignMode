#pragma once

#include <iostream>

// �������,��װ�ζ���
class Component {
public:
    virtual void operation() = 0;
};

// �������
class ConcreteComponent : public Component {
public:
    void operation() {
        std::cout << "ConcreteComponent: Operation." << std::endl;
    }
};

// ����װ����
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* comp) : component(comp) {}

    void operation() {
        component->operation();
    }
};

// ����װ���� A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

    void operation() {
        Decorator::operation();
        std::cout << "ConcreteDecoratorA: Additional operation A." << std::endl;
    }
};

// ����װ���� B
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
/*�����
ConcreteComponent: Operation.
ConcreteComponent : Operation.
ConcreteDecoratorA : Additional operation A.
ConcreteComponent : Operation.
ConcreteDecoratorA : Additional operation A.
ConcreteDecoratorB : Additional operation B.
*/
/*���ۣ�
���Կ�����װ��ģʽͨ��װ�������Ƕ����ϣ���̬��Ϊ��������µ���Ϊ��������Ҫ�ı���ԭʼ��ṹ��
��������ʵ�ֹ��ܵĶ�̬��Ϻ���չ��ͬʱ���ִ��������ԺͿ�ά���ԡ�
*/