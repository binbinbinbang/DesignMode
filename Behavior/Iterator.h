#pragma once
#include <iostream>
#include <vector>

// �������ӿ�
class Iterator {
public:
    virtual int next() = 0;
    virtual bool hasNext() = 0;
};

// ���������
class ConcreteIterator : public Iterator {
private:
    std::vector<int>& collection;
    int position;

public:
    ConcreteIterator(std::vector<int>& coll) : collection(coll), position(0) {}

    int next() override {
        return collection[position++];
    }

    bool hasNext() override {
        return position < collection.size();
    }
};

// �ۺ϶���ӿ�
class Aggregate {
public:
    virtual Iterator* createIterator() = 0;
};

// ����ۺ϶���,����list��map
class ConcreteAggregate : public Aggregate {
private:
    std::vector<int> collection;

public:
    ConcreteAggregate() {
        collection.push_back(1);
        collection.push_back(2);
        collection.push_back(3);
        collection.push_back(4);
        collection.push_back(5);
    }

    Iterator* createIterator() override {
        return new ConcreteIterator(collection);
    }
};

int main() {
    ConcreteAggregate aggregate;
    Iterator* iterator = aggregate.createIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl;

    delete iterator;

    return 0;
}
