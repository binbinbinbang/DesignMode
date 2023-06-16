#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

// 抽象策略类
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
};

// 具体策略类 - 快速排序
class QuickSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Using Quick Sort" << std::endl;
        std::sort(data.begin(), data.end());
    }
};

// 具体策略类 - 冒泡排序
class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Using Bubble Sort" << std::endl;
        // 冒泡排序的实现
    }
};

// 环境类context
class Sorter {
private:
    SortingStrategy* strategy;

public:
    void setStrategy(SortingStrategy* strategy) {
        this->strategy = strategy;
    }

    void performSort(std::vector<int>& data) {
        strategy->sort(data);
    }
};

int main() {
    Sorter sorter;

    // 使用快速排序
    QuickSortStrategy quickSortStrategy;
    sorter.setStrategy(&quickSortStrategy);

    std::vector<int> data = {5, 2, 8, 1, 4};
    sorter.performSort(data);

    // 使用冒泡排序
    BubbleSortStrategy bubbleSortStrategy;
    sorter.setStrategy(&bubbleSortStrategy);

    sorter.performSort(data);

    return 0;
}
