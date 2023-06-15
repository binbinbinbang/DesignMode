#pragma once
#include <iostream>
//责任链模式，可以处理复杂的else if情况。
// 抽象处理者
class Handler {
protected:
    Handler* nextHandler;

public:
    Handler() : nextHandler(nullptr) {}

    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

    virtual void handleRequest(int request) = 0;
};

// 具体处理者 A
class ConcreteHandlerA : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 0 && request < 10) {
            std::cout << "ConcreteHandlerA 处理请求 " << request << std::endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
    }
};

// 具体处理者 B
class ConcreteHandlerB : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            std::cout << "ConcreteHandlerB 处理请求 " << request << std::endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
    }
};

// 具体处理者 C
class ConcreteHandlerC : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 20 && request < 30) {
            std::cout << "ConcreteHandlerC 处理请求 " << request << std::endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        }
    }
};

int main() {
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;
    ConcreteHandlerC handlerC;

    handlerA.setNextHandler(&handlerB);
    handlerB.setNextHandler(&handlerC);

    handlerA.handleRequest(5);
    handlerA.handleRequest(15);
    handlerA.handleRequest(25);

    return 0;
}

