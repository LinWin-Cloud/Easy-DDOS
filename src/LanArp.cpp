//
// Created by ubuntu on 24-2-12.
//

#include "config.h"

string lan_arp_linux() {
    stringstream ss;
    FILE* f_pop = popen("arp-scan -l" , "r");
    if (!f_pop) {
        throw runtime_error("arp-scan error.");
    } else {
        char buffer[256];
        while (fgets(buffer , sizeof(buffer) , f_pop) != nullptr ) {
            ss << buffer;
        }
        pclose(f_pop);
        return ss.str();
    }
}