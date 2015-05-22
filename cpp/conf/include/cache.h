#include "hunter-include.h"
#include "conf.h"
#include "cache_key.h"
#include "mysql.h"

class cache_key_factory {

	public:
		int load(config& conf);
		std::vector<cache_key> table2key();

	private:
		std::map< std::string, std::vector<cache_key> > m_key_map;
		config* m_conf;
};
