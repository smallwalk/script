#ifndef _IDALLOCATOR_H
#define _IDALLOCATOR_H

class IDAllocator {
	
public:
	virtual ~IDAllocator() {}

	/**
	 * 初始化
	 */
	virtual int init(const char* path, const char* id_type)=0;

	/**
	 * 获取id类型名称
	 */
	virtual const char* get_id_type()=0;

	/**
	 * 判断一个id是否合法
	 */
	virtual bool is_valid(int64_t id)=0;

	/**
	 * id分配
	 */
	virtual int64_t get_id(cm_binlog_t *binlog)=0;

	/**
	 * 回收一个id，被回收的id会被优先使用
	 */
	virtual int recycle_id(int64_t id, cm_binlog_t *binlog)=0;

	/**
	 * 销毁
	 */
	virtual int destroy()=0;
};

#endif
