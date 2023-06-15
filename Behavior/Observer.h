#pragma once
#include <iostream>
#include <vector>

// �۲��߽ӿ�
class Observer {
public:
    virtual void update(int value) = 0;
};

// ����۲���
class ConcreteObserver : public Observer {
public:
    void update(int value) override {
        std::cout << "���յ����£���ֵΪ: " << value << std::endl;
    }
};

// ����ӿ�
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// ��������
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

