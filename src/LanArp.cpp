//
// Created by ubuntu on 24-2-12.
//

#include "config.h"

string lan_arp_linux() {
    FILE* f_pop = popen("arp-scan -n" , "r");
    if (!f_pop) {
        throw runtime_error("arp-scan error.");
    } 
}