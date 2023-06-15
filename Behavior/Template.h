#pragma once
#include <iostream>
//模板方法模式，可以用来分工合作写代码。大佬定义一个模板，让徒弟去实现某一部分具体的算法。
// 抽象类
class CoffeeMaker {
public:
    // 模板方法，定义制作咖啡的算法骨架
    void makeCoffee() {
        boilWater();
        brewCoffee();//煮咖啡
        pourInCup();
        addCondiments();//加小料
        std::cout << "咖啡已制作完成！" << std::endl;
    }

    // 具体步骤的纯虚函数，由子类提供实现
    virtual void brewCoffee() = 0;
    virtual void addCondiments() = 0;

    // 具体步骤的默认实现
    void boilWater() {
        std::cout << "将水煮沸" << std::endl;
    }

    void pourInCup() {
        std::cout << "将咖啡倒入杯子" << std::endl;
    }
};

// 具体子类
class EspressoMaker : public CoffeeMaker {
public:
    void brewCoffee() override {
        std::cout << "用沸水冲泡浓缩咖啡" << std::endl;
    }

    void addCondiments() override {
        std::cout << "加入少量糖和牛奶" << std::endl;
    }
};

class CappuccinoMaker : public CoffeeMaker {
public:
    void brewCoffee() override {
        std::cout << "用沸水冲泡浓缩咖啡" << std::endl;
    }

    void addCondiments() override {
        std::cout << "加入大量奶泡和可可粉" << std::endl;
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
