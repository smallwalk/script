#include "IDAllocatorManager.h"

int 
IDAllocatorManager::init(const char* path, const char* filename) 
{
	int id_type;
	int step_interval;
	int ret;
	unsigned int i;
	unsigned int _allocater_num = 3;

	for(i=0; i<_allocater_num; i++) {
		switch (id_type) {
			case ID_ALLOCATOR_STEP:
				if (step_interval <= 0) {
					_allocaters[i] = new(std::nothrow)StepIDAllocator();
				} else {
					_allocaters[i] = new(std::nothrow)StepIDAllocator(step_interval);
				}
				break;
			default:
				return 0;
		}
		ret = _allocaters[i]->init(_allocator_path, _id_types[i]);
	}

	return 0;
}
