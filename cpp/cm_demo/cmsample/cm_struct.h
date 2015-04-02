#ifndef __ECHO_DATA_H__
#define __ECHO_DATA_H__

#include "cm_include.h"

///SERVER服务的配置信息
typedef struct _g_conf_t {

    char conf_dir[PATH_SIZE];             /**<   配置文件的目录    */
    char conf_file[PATH_SIZE];            /**<   配置文件名        */
    char data_dir[PATH_SIZE];             /**<   数据文件的根目录  */

    //char id_dir[PATH_SIZE];           /**<   id 分配使用的目录 */
    char di_dir[PATH_SIZE];             /**<   di 存放目录 */

    char log_dir[PATH_SIZE];              /**<   日志文件的根目录  */
    char log_file[PATH_SIZE];             /**<   日志文件名        */
    int log_level;                    /**<   日志级别          */
    int log_size;                     /**<   日志回滚的大小(M) */
    //u_int daemon_sleeptime;               /**<   定时线程的sleep间隔(ms) */

    //ub_svr_t cm;                      /**<   cm的配置信息 */
    char auth_file[PATH_SIZE];            /**<   认证文件路径           */

    // di related.
    int idxfile_perdir;           /**<  di 目录一个目录中多少个index文件      */
    char write_record_file[PATH_SIZE];        /**<  write record file name      */
    char base_name[PATH_SIZE];            /**<  di文件的前缀名      */
    unsigned int howlong_cancommit;       /**<  多久可以认为已经写入      */
    unsigned int sync_perx;       /**<  di写入多少命令sync一次.      */
    // binlog
    unsigned int binlog_cmd_num_threshold;        /**<   多少条命令写入binlog一次     */

    // parallel lock
    unsigned int cmd_parallel_group_num;          /**<   命令分组的数目     */
} g_conf_t;

///SERVER相关数据
typedef struct _cm_data_t {

    char binlog_buf[BINLOG_BUF_SIZE]; // binlog buf 
    unsigned int binlog_cmd_num;          // 已经写入多少cmd,用于计算是否需要写binlog.

	/*
    ub_auth_t   *auth;                    //   IP认证    
    ub_client_t *client;              //   客户端   
    ub_server_t *cm_svr;          //  cm服务       

    //id allocator
    IDAllocatorManager * id_allocator; // id分配器 
    pthread_mutex_t allocator_lock;       //allocator的锁.      

    // key value manager.
    HashDataManager * cmdata; // key -value 数据管理 
    pthread_mutex_t cmdata_lock;          // 数据 管理的锁      
    //ArrayDataManager * cmdata; // key -value 数据管理 

    //di
    transdi_file_t  di_file;    // di 
    cm_binlog_t  binlog;        // binlog 单点备份
    char binlog_buf[BINLOG_BUF_SIZE]; // binlog buf 
    unsigned int binlog_cmd_num;          // 已经写入多少cmd,用于计算是否需要写binlog.
    pthread_mutex_t di_lock;          // di 的锁,多线程互斥 
    // locks.
    Cwp_rwlock * g_serial_lock;       //    全局串行锁 
    pthread_mutex_t * group_locks;        //   各个命令分组的锁 
	*/
} cm_data_t;

extern g_conf_t g_conf; //全局配置
extern cm_data_t g_cm; //全局数据

#endif
