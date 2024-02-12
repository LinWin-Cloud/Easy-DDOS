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

vector<string> lan_ip_address() {
    vector<string> ips;
    string lan_arp = lan_arp_linux();
    vector<string> line_arp = split(lan_arp , "\n");
    for (int i = 2;i < line_arp.size() ;i++) {
        if (i >= line_arp.size() -3) {
            break;
        }
        const char *a = "\t";
        const char *b = " ";
        string ip = replaceAll_Cpp(line_arp[i] ,  *a,*b).substr(0,ip.find(' '));
        ip = trim(ip);
        cout << " [INFO] Scan ==>" << endl;
        cout << ip << endl;
        ips.push_back(ip);
    }
    return ips;
}