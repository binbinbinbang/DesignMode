#pragma once
#include <iostream>

// Ŀ��ӿ�
class Target {
public:
    virtual void request() = 0;
};

// ���������
class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee: Specific request." << std::endl;
    }
};

// ��������
class Adapter : public Target, private Adaptee {
    //˽�м̳У���������Է��ʻ���ĳ�Ա�������ⲿ���ܷ��ʻ���ĳ�Ա���ܺõ�������ϸ�ڡ�
public:
    void request() {
        std::cout << "Adapter: Adapted request." << std::endl;
        specificRequest();
    }
};

// ����������
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
    //˽�м̳з�ʽ ����
    Target* target = new Adapter();
    target->request();

    //ע�뷽ʽ
    Adaptee* adaptee = new Adaptee();
    Target* target2 = new Adapter2(adaptee);
    target2->request();

    return 0;
}
