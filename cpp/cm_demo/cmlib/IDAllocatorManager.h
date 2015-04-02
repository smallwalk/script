#ifndef _IDALLOCATORMANAGER_H
#define _IDALLOCATORMANAGER_H

#define MAX_IDALLOCATOR_NUM 1024

enum id_allocator_type {
	ID_ALLOCATOR_STEP = 1, //递增ID分配器	
	ID_ALLOCATOR_STEP_RECYCLE = 2,
	ID_ALLOCATOR_RAND = 3,
	ID_ALLOCATOR_RAND_RECYCLE = 4,
}

class IDAllocatorManager {
public:
	/**
	 * 初始化，传入配置文件
	 */
	int init(const char* path, const char* filename);

	/**
	 * 判断id是否有效
	 */
	bool is_valid(const char* id_type, int64_t id);

	/**
	 * 分配id
	 */
	int64_t get_id(const char* id_type, cm_binlog_t *binlog);

	/**
	 * 回收id
	 */
	int recycle_id(const char* id_type, int64_t id, cm_binlog_t *binlog);

	int destroy();

	IDAllocatorManager();
	~IDAllocatorManager();

private:
	/**
	 * 根据id类型字符串找到其索引
	 */
	int get_index(const char* id_type);

private:
	IDAllocator * _allocaters[MAX_IDALLOCATOR_NUM]; //id分配器
	char _allocator_path[PATH_SIZE]; //id相关文件存储路径
	char _id_types[MAX_IDALLOCATOR_NUM][PATH_SIZE]; //id type数组
	unsigned int _allocater_num; //分配器数目
}

#endif
