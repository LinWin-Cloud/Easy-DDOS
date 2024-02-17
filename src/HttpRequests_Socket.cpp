//
// Created by ubuntu on 24-2-17.
//
#include "config.h"
#include <regex>

class HttpRequests_Socket{
private:
    std::string getHostFromURL(const std::string& url) {
        std::smatch match;
        std::regex pattern(
                R"regex(^(?:http|ftp)s?://(?P<host>[^:/\s]+))regex",
                std::regex_constants::icase);
        if (std::regex_search(url, match, pattern)) {
            return match[(unsigned long) "host"].str();
        }
        return ""; // 如果没有找到匹配项，返回空字符串
    }
public:

};