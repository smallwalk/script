#include "cache.h"

int main() {
    config my_conf("conf/binlog-hunter.conf");
    int log_level = my_conf["log"]["debug"].to_int();

    cache_key_factory m_cache_key;
    m_cache_key.load(my_conf);

    std::vector<cache_key> ck = m_cache_key.table2key();


    for (int i=0; i<ck.size(); i++) {
        std::cout << ck[i].prefix << std::endl;
    }

    return 0;
}
