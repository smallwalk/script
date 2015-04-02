#include "StepIDAllocator.h"

int 
StepIDAllocator::init(const char* path, const char* id_type) {

	snprintf(_path, sizeof(_path), "%s", path);
	snprintf(_id_type, sizeof(_id_type), "%s", id_type);

	int ret = get_cur_id(_path, _id_type, _cur_max_id);

	return 0;
}

const char* 
StepIDAllocator::get_id_type() {
	return _id_type;
}

bool 
StepIDAllocator::is_valid(int64_t id) {
	if (id > 0 && id < _cur_max_id) {
		return true;
	}
	return false;
}

int64_t 
StepIDAllocator::get_id(cm_binlog_t *binlog) {
	int64_t alloc_id = _cur_max_id;
	_cur_max_id += _step_interval;
	int ret = save_cur_id(_path, _id_type, _cur_max_id, binlog);

	return alloc_id;
}

const char* 
StepIDAllocator::recycle_id(int64_t id, cm_binlog_t *binglog) {
	return 0;
}

StepIDAllocator::StepIDAllocator() {
	_cur_max_id = 0;
	_id_type[0] = 0;
	_path[0] = 0;
	_step_interval = DEFAULT_STEP_INTERVAL;
}

StepIDAllocator::~StepIDAllocator() {
	
}

int StepIDAllocator::get_cur_id(const char* path, const char* id_type, int64_t & cur_id) {
		
	char filename[PATH_SIZE];
	char tmpbuf[PATH_SIZE];
	int64_t tmpid;
	snprintf(filename, sizeof(filename), "%s/%s.cur_id", path, id_type);

	FILE *fp = fopen(filename "r");
	if (fp == NULL) {
		return -1;
	}

	int ret = fscanf(fp, "%s : %ld\n", tmpbuf, &tmpid);

	if (ret != 2) {
		fclose(fp);
		return -1;
	}
	if (tmpid <= 0) {
		fclose(fp);
		return -1;
	}

	fclose(fp);
	cur_id = tmpid;
	return 0;
}

int StepIDAllocator::save_cur_id(const char* path, const char* id_type, int64_t cur_id, cm_binlog_t *binlog) {
	
	char filename[PATH_SIZE];
	char tmpbuf[BINLOG_BUF_LEN];

	snprintf(filename, sizeof(filename), "%s/%s.cur_id", path, id_type);

	FILE *fp = fopen(filename, "r+");
	if (fp == NULL) {
		return -1;
	}

}



