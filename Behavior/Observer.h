#pragma once
#include <iostream>
#include <vector>

// 观察者接口
class Observer {
public:
    virtual void update(int value) = 0;
};

// 具体观察者
class ConcreteObserver : public Observer {
public:
    void update(int value) override {
        std::cout << "接收到更新，新值为: " << value << std::endl;
    }
};

// 主题接口
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// 具体主题
class ConcreteSubject : public Subject {
private:
    std::vector<Observer*> observers;
    int value;

public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update(value);
        }
    }

    void setValue(int newValue) {
        value = newValue;
        notify();
    }
};

int main() {
    ConcreteSubject subject;
    ConcreteObserver observer1;
    ConcreteObserver observer2;

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setValue(10);

    subject.detach(&observer1);

    subject.setValue(20);

    return 0;
}

