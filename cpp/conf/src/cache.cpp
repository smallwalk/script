#include "cache.h"

int cache_key_factory::load(config& conf) {
	m_conf = &conf;
	elem_group& db = conf["cache"]["db"];
	for (size_t i = 0; i < db.size(); i++) {
		//db config
		config db_key_map(("conf/" + db[i].to_string() + ".conf").c_str());

		//table
		for (config::iterator it=db_key_map.begin(); it != db_key_map.end(); it++) {
			std::string table = it->first;
			//cache key name(prefix)，一个表可能存在多个类型的key
			elem_group& key_base = db_key_map[table.c_str()]["prefix"];
			std::vector<cache_key> ck_vec;

			for (size_t x = 0; x < key_base.size(); x++) {
				//获取x的字符串
				char buf[32];
				sprintf(buf, "%d", x);
				buf[31] = 0;
				cache_key ck;
				ck.prefix = key_base[x].to_string();
				std::string key_suffix = "suffix";
				std::string key_split = "split";
				std::string key_field = "field";
				std::string key_column = "column";
				if (x > 0) {
					key_suffix += buf;
					key_split += buf;
					key_field += buf;
					key_column += buf;
				}

				ck.suffix = db_key_map[table.c_str()][key_suffix.c_str()].to_string();
				ck.split = db_key_map[table.c_str()][key_split.c_str()].to_string();
				elem_group& eg = db_key_map[table.c_str()][key_field.c_str()];
				for(size_t j = 0; j < eg.size(); j++){
					ck.fields_order.push_back(eg[j].to_string());
				}
				/*
				elem_group& col = db_key_map[table.c_str()][key_column.c_str()];
				std::vector<std::string> desc;
				for(size_t j = 0; j < col.size(); j++){
					desc.push_back(col[j].to_string());
				}
				*/

				// table-key 加入表cache集合
				ck_vec.push_back(ck);
			}
			std::string key = db[i].to_string()+table;

			for (int l=0; l < ck_vec.size(); l++) {
				std::cout << key << std::endl;
			}

			m_key_map[key] = ck_vec;
		}
	}
	return 0;
}

std::vector<cache_key> cache_key_factory::table2key() {
	return m_key_map["brd_shopbrd_goods_info"];
}
