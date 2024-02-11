//
// Created by ubuntu on 24-2-10.
//
#include "config.h"
using namespace std;

string version_name = "1.0 Public";


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
            
        }
        else {
            cout << "[!] ERROR INPUT: " << command << endl; // error command.
        }
    }
    return 0;
}