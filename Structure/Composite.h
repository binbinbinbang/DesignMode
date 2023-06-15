#pragma once
#include <iostream>
#include <vector>
//组合模式，适用于整体和部分关系，有相同的操作，树形结构。
// 组件抽象类
class Component {
public:
    virtual void operation() const = 0;
    virtual void add(Component* component) {}//不能是抽象方法，否则 Leaf也要实现该方法
    virtual void remove(Component* component) {}
};

// 叶节点类
class Leaf : public Component {
public:
    void operation() const {
        std::cout << "Leaf: Operation." << std::endl;
    }

};

// 组合节点类
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void remove(Component* component) {
        // 在实际应用中，可能需要遍历 children 来查找要删除的 component
        // 这里简化实现，直接假设要删除的 component 已经在 children 中
        children.erase(std::remove(children.begin(), children.end(), component), children.end());
    }

    void operation() const {
        std::cout << "Composite: Operation." << std::endl;

        // 调用所有子节点的 operation 方法
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

    // 释放内存
    delete composite2;

    return 0;
}
/*
请注意，组合模式的关键是在组合节点类中定义add()和remove()等管理子节点的操作，而叶节点类没有这些操作。
这样，我们可以一致地对待叶节点和组合节点，并通过组合节点来管理一组子节点。
*/