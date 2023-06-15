#pragma once
#include <iostream>
//ģ�巽��ģʽ�����������ֹ�����д���롣���ж���һ��ģ�壬��ͽ��ȥʵ��ĳһ���־�����㷨��
// ������
class CoffeeMaker {
public:
    // ģ�巽���������������ȵ��㷨�Ǽ�
    void makeCoffee() {
        boilWater();
        brewCoffee();//�󿧷�
        pourInCup();
        addCondiments();//��С��
        std::cout << "������������ɣ�" << std::endl;
    }

    // ���岽��Ĵ��麯�����������ṩʵ��
    virtual void brewCoffee() = 0;
    virtual void addCondiments() = 0;

    // ���岽���Ĭ��ʵ��
    void boilWater() {
        std::cout << "��ˮ���" << std::endl;
    }

    void pourInCup() {
        std::cout << "�����ȵ��뱭��" << std::endl;
    }
};

// ��������
class EspressoMaker : public CoffeeMaker {
public:
    void brewCoffee() override {
        std::cout << "�÷�ˮ����Ũ������" << std::endl;
    }

    void addCondiments() override {
        std::cout << "���������Ǻ�ţ��" << std::endl;
    }
};

class CappuccinoMaker : public CoffeeMaker {
public:
    void brewCoffee() override {
        std::cout << "�÷�ˮ����Ũ������" << std::endl;
    }

    void addCondiments() override {
        std::cout << "����������ݺͿɿɷ�" << std::endl;
    }
};

int main() {
    CoffeeMaker* espressoMaker = new EspressoMaker();
    espressoMaker->makeCoffee();

    std::cout << std::endl;

    CoffeeMaker* cappuccinoMaker = new CappuccinoMaker();
    cappuccinoMaker->makeCoffee();

    delete espressoMaker;
    delete cappuccinoMaker;

    return 0;
}
