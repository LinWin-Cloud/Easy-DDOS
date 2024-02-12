//
// Created by ubuntu on 24-2-10.
//

#include "config.h"


using namespace std;

string input(const string& charset) {
    string userInput;
    printf("%s", charset.c_str());
    getline(std::cin , userInput);
    return userInput;
}

string trim(string str) {
    str.erase(0, str.find_first_not_of(' ')); // 去除开头空格
    str.erase(str.find_last_not_of(' ') + 1, str.length()); // 去除结尾空格
    return str;
}

string get_login_user_linux() {
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        return pw -> pw_name;
    } else {
        throw runtime_error("Can not get login user.");
    }
}