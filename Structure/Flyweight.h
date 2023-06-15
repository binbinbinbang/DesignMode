#pragma once
#include <iostream>
#include <unordered_map>
//����ϸ���ȵĶ��󣬲����ظ������������ϵͳ���ܡ�
// ��Ԫ�ӿ�
class Flyweight {
public:
    virtual void operation(int extrinsicState) = 0;
};

// ������Ԫ��
class ConcreteFlyweight : public Flyweight {
private:
    int intrinsicState; // �ڲ�״̬

public:
    ConcreteFlyweight(int intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(int extrinsicState) {
        std::cout << "ConcreteFlyweight: Intrinsic State = " << intrinsicState;
        std::cout << ", Extrinsic State = " << extrinsicState << std::endl;
    }
};

// ��Ԫ������
class FlyweightFactory {
private:
    std::unordered_map<int, Flyweight*> flyweights; // ��Ԫ�أ����������̳߳أ����ݿ����ӳ�

public:
    Flyweight* getFlyweight(int key) {
        if (flyweights.find(key) != flyweights.end()) {
            // �����Ԫ�����Ѵ��ڶ�Ӧ����Ԫ������ֱ�ӷ���
            return flyweights[key];
        }
        else {
            // �����Ԫ���в����ڶ�Ӧ����Ԫ�����򴴽��µ���Ԫ���󲢴洢����Ԫ����
            Flyweight* flyweight = new ConcreteFlyweight(key);
            flyweights[key] = flyweight;
            return flyweight;
        }
    }
};

int main() {
    FlyweightFactory factory;

    // ��һ�λ�ȡ��Ԫ���󣬽��ᴴ���µ���Ԫ����
    Flyweight* flyweight1 = factory.getFlyweight(1);
    flyweight1->operation(100);

    // �ٴλ�ȡ��ͬ����Ԫ���󣬽���ֱ��ʹ���Ѵ��ڵ���Ԫ����
    Flyweight* flyweight2 = factory.getFlyweight(1);
    flyweight2->operation(200);

    // ��ȡ��ͬ����Ԫ����
    Flyweight* flyweight3 = factory.getFlyweight(2);
    flyweight3->operation(300);

    return 0;
}
/*
�����
ConcreteFlyweight: Intrinsic State = 1, Extrinsic State = 100
ConcreteFlyweight: Intrinsic State = 1, Extrinsic State = 200
ConcreteFlyweight: Intrinsic State = 2, Extrinsic State = 300
*/
/*
���ۣ�
���Կ�����ͨ��������Ԫ�������ǿ��Խ�ʡ�ڴ�ռ䣬��������Ҫʱ�����Ѵ����Ķ������ϵͳ���ܡ�
��Ԫģʽ��������Ҫ��������ϸ���ȶ��󣬲�����Щ����֮������๲ͬ�����Ժ���Ϊ�������
*/