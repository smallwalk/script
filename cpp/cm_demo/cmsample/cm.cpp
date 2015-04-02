#include "cm_include.h"

g_conf_t g_conf; //全局配置
cm_data_t g_cm; //全局数据

static void
print_help()
{
    printf("\t-d:     conf_dir\n");
    printf("\t-f:     conf_file\n");
    printf("\t-h:     show this help page\n");
    printf("\t-t:     check config file syntax\n");
    printf("\t-g:     generate config sample file\n");
    printf("\t-v:     show version infomation\n");
    return;
}

/**
 * 初始化配置
 *
 * @param[int] conf_check 配置检查
 * @param[int] build 生成配置文件
 *
 * @return 0:成功
 * 		   1:失败，退出
 */
static int
init_config(int conf_check, int conf_build) 
{
	int ret;
	if (conf_check) {
		ret = serv_checkconf(g_conf.conf_dir, g_conf.conf_file);	
	}
	return 0;
}

static int
serv_checkconf(const char *dir, const char *file)
{
	if (0 != serv_loadconf(dir, file, 0)) {
		return -1;
	}
	return 0;
}


/**
 * 读取配置文件
 *
 * return 0:成功 -1:失败
 */
static int 
serv_loadconf(const char *dir, const char *file, int build) 
{
	//初始化配置库，打开配置信息
	//ub_conf_data_t *conf = ub_conf_init(dir, file, build);
	return 0;
}

static int
global_data_init()
{
	g_cm.id_allocator = new (std::nothrow) IDAllocatorManager();
}

int
main(int argc, char ** argv)
{

	int c = 0;
	int conf_build = 0;    //读取配置还是生成配置文件
	int conf_check = 0;    //是否只是进行配置文件的语法检查

	strlcpy(g_conf.conf_dir, DEF_CONF_DIR, PATH_SIZE);	
	strlcpy(g_conf.conf_file, DEF_CONF_FILE, PATH_SIZE);

	while (-1 != (c = getopt(argc, argv, "d:f:gthv"))) {
		switch (c) {
			case 'g':
				conf_build = 1;
				break;
			case 't':
				conf_check = 1;
				break;
			case 'h':
			default:
				print_help();
				return 0;
		}
	}

	if (0 != init_config(conf_build, conf_check)) {
		
	}

	ret = global_data_init();

	return 0;
}
