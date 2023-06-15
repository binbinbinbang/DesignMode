#pragma once
#include <iostream>
#include <vector>
//���ģʽ������������Ͳ��ֹ�ϵ������ͬ�Ĳ��������νṹ��
// ���������
class Component {
public:
    virtual void operation() const = 0;
    virtual void add(Component* component) {}//�����ǳ��󷽷������� LeafҲҪʵ�ָ÷���
    virtual void remove(Component* component) {}
};

// Ҷ�ڵ���
class Leaf : public Component {
public:
    void operation() const {
        std::cout << "Leaf: Operation." << std::endl;
    }

};

// ��Ͻڵ���
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void remove(Component* component) {
        // ��ʵ��Ӧ���У�������Ҫ���� children ������Ҫɾ���� component
        // �����ʵ�֣�ֱ�Ӽ���Ҫɾ���� component �Ѿ��� children ��
        children.erase(std::remove(children.begin(), children.end(), component), children.end());
    }

    void operation() const {
        std::cout << "Composite: Operation." << std::endl;

        // ���������ӽڵ�� operation ����
        for (Component* component : children) {
            component->operation();
        }
    }
};

int main() {
    Component* leaf = new Leaf();

    Component* composite1 = new Composite();
    composite1->add(leaf);

    Component* composite2 = new Composite();
    composite2->add(composite1);

    composite2->operation();

    // �ͷ��ڴ�
    delete composite2;

    return 0;
}
/*
��ע�⣬���ģʽ�Ĺؼ�������Ͻڵ����ж���add()��remove()�ȹ����ӽڵ�Ĳ�������Ҷ�ڵ���û����Щ������
���������ǿ���һ�µضԴ�Ҷ�ڵ����Ͻڵ㣬��ͨ����Ͻڵ�������һ���ӽڵ㡣
*/