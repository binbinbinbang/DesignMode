#pragma once
#include <iostream>
#include <string>

// ��Ʒ��
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

// �����߽ӿ�
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getProduct() = 0;
};

// ���彨����A
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

// ���彨����B
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

// ָ����
class Director {
public:
    void construct(Builder* builder) {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

int main() {
    Director director;//�����ߣ�ָ�Ӽң�����ͷ������

    ConcreteBuilderA builderA;//�������ˣ��泵����
    director.construct(&builderA);
    Product* productA = builderA.getProduct();//�ֽ�ˮ��
    productA->show();

    ConcreteBuilderB builderB;//�������ˣ���ˢ����
    director.construct(&builderB);
    Product* productB = builderB.getProduct();//��ǽ��ˢ
    productB->show();

    delete productA;
    delete productB;

    return 0;
}
