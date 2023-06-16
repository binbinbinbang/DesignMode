#pragma once
#include <iostream>
//命令模式，将命令包装成对象，可以实现命令的参数化和队列化。发送者和接收者解耦。
// 命令接口
class Command {
public:
    virtual void execute() = 0;
};

// 具体命令 - 打开电灯
class LightOnCommand : public Command {
private:
    Light& light;

public:
    LightOnCommand(Light& light) : light(light) {}

    void execute() override {
        light.on();
    }
};

// 具体命令 - 关闭电灯
class LightOffCommand : public Command {
private:
    Light& light;

public:
    LightOffCommand(Light& light) : light(light) {}

    void execute() override {
        light.off();
    }
};

// 接收者 - 电灯
class Light {
public:
    void on() {
        std::cout << "Light is on" << std::endl;
    }

    void off() {
        std::cout << "Light is off" << std::endl;
    }
};

// 发送者 - 遥控器
class RemoteControl {
private:
    Command* command;

public:
    void setCommand(Command* command) {
        this->command = command;
    }

    void pressButton() {
        command->execute();
    }
};

int main() {
    Light light;
    LightOnCommand lightOnCommand(light);
    LightOffCommand lightOffCommand(light);

    RemoteControl remoteControl;

    // 打开电灯
    remoteControl.setCommand(&lightOnCommand);
    remoteControl.pressButton();

    // 关闭电灯
    remoteControl.setCommand(&lightOffCommand);
    remoteControl.pressButton();

    return 0;
}
