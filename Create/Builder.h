#pragma once
#include <iostream>
#include <string>

// 产品类
class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void show() {
        std::cout << "Product parts:" << std::endl;
        std::cout << "Part A: " << partA_ << std::endl;
        std::cout << "Part B: " << partB_ << std::endl;
        std::cout << "Part C: " << partC_ << std::endl;
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

// 建造者接口
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getProduct() = 0;
};

// 具体建造者A
class ConcreteBuilderA : public Builder {
public:
    void buildPartA() {
        product_->setPartA("Part A - Builder A");
    }

    void buildPartB() {
        product_->setPartB("Part B - Builder A");
    }

    void buildPartC() {
        product_->setPartC("Part C - Builder A");
    }

    Product* getProduct() {
        return product_;
    }

private:
    Product* product_ = new Product();
};

// 具体建造者B
class ConcreteBuilderB : public Builder {
public:
    void buildPartA() {
        product_->setPartA("Part A - Builder B");
    }

    void buildPartB() {
        product_->setPartB("Part B - Builder B");
    }

    void buildPartC() {
        product_->setPartC("Part C - Builder B");
    }

    Product* getProduct() {
        return product_;
    }

private:
    Product* product_ = new Product();
};

// 指挥者
class Director {
public:
    void construct(Builder* builder) {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

int main() {
    Director director;//管理者，指挥家，包工头，经理。

    ConcreteBuilderA builderA;//建筑工人（叉车工）
    director.construct(&builderA);
    Product* productA = builderA.getProduct();//钢筋水泥
    productA->show();

    ConcreteBuilderB builderB;//建筑工人（粉刷匠）
    director.construct(&builderB);
    Product* productB = builderB.getProduct();//砌墙粉刷
    productB->show();

    delete productA;
    delete productB;

    return 0;
}
