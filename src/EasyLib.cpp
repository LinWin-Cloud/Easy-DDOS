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

vector<string> split(string str , string split_charset) {
    vector<string> split;
    size_t pos = str.find(split_charset);
    while (pos != std::string::npos) {
        std::string word = str.substr(0, pos);
        split.push_back(word);
        // 移除已处理的子字符串
        str = str.substr(pos + 1);
        pos = str.find(split_charset);
    }
    split.push_back(str);
    return split;
}

string replaceAll_Cpp(string str_to , char charToReplace , char newChar) {
    // 遍历字符串，并替换所有出现的charToReplace字符
    string str = std::move(str_to);
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == charToReplace) {
            str[i] = newChar;
        }
    }
    return str;
}