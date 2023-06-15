#pragma once
#include <iostream>
//����ģʽ���ŵ������
//
//���ԶԿͻ���������ʵ����ľ���ʵ�֣��ṩ��һ�ּ�ӷ��ʵķ�ʽ��
//�����ڷ�����ʵ����֮ǰ��֮����Ӷ�����߼�������Ȩ����֤������ȡ�
//���Զ���ʵ����ķ������п��ƣ��������Ʒ����ĵ��ô������ӳټ��صȡ�
//����ģʽ��ȱ�������
//
//���������˴�����󣬿��ܻ�����ϵͳ�ĸ����ԡ�
//���ܻ�Ӱ��ϵͳ�����ܣ���Ϊ������Ҫ�������Ĳ�����
//����ģʽ���������������
//
//��Ҫ���ƶ�һ������ķ��ʣ����ڷ���ǰ��ִ�ж���Ĳ�����
//��Ҫ��ԭʼ������а�װ�����ṩ����Ĺ��ܻ��޸�ԭʼ�������Ϊ��
//��Ҫͨ�������м�����򻯿ͻ�������ʵ����֮��Ľ�����
//�ܽ�����������ģʽͨ������һ��������������ƶ���һ������ķ��ʣ��Ӷ�ʵ�ֶ���ʵ����ļ�ӷ��ʺͿ��ơ����ṩ��һ�����ķ�ʽ����Ӷ���Ĺ��ܣ�ͬʱҲ����������ʵ����ľ���ʵ�֡�


// ��������
class Subject {
public:
    virtual void request() = 0;
};

// ��ʵ����
class RealSubject : public Subject {
public:
    void request() {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// ��������
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    void request() {
        if (realSubject == nullptr) {
            realSubject = new RealSubject();
        }

        // ���ƺ���ǿ��ʵ����ķ�������
        std::cout << "Proxy: Pre-processing request." << std::endl;
        realSubject->request();
        std::cout << "Proxy: Post-processing request." << std::endl;
    }
};

int main() {
    Proxy proxy;
    proxy.request();

    return 0;
}
