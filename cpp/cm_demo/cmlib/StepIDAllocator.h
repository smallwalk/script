#ifndef _STEPIDALLOCATOR_H
#define _STEPIDALLOCATOR_H

#include "transdifile.h"
#include "IDAllocator.h"

class StepIDAllocator : public IDAllocator {
public:
	virtual int init(const char* path, const char* id_type);

	virtual const char* get_id_type();

	virtual bool is_valid(int64_t id);

	virtual int64_t get_id(cm_binlog_t *binlog);

    virtual int recycle_id(int64_t id, cm_binlog_t * binlog);

    virtual int destroy();

    StepIDAllocator();
    StepIDAllocator(int step_interval);

    virtual ~StepIDAllocator();

private:
	static int get_cur_id(const char* path, const char* id_type, int64_t & cur_id);
	static int save_cur_id(const char* path, const char* id_type, int64_t cur_id, cm_binlog_t *binlog);

public:
	static const int DEFAULT_STEP_INTERVAL = 1; 

protected:
	int64_t _cur_max_id; //当前分配到的最大id
	char _id_type[PATH_SIZE]; //id类型
	char _path[PATH_SIZE]; //id文件存储路径
	int _step_interval; //步长
};

#endif
