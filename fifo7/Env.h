#ifndef __ENV_H
#define __ENV_H

/***** FIFO ******/
#define SERVER_FIFO_NAME "/tmp/server_fifo"
#define CLIENT_FIFO_NAME "/tmp/client_%d_fifo"
#define SOFT_UPDATE_FIFO_NAME "/tmp/client_soft_upgrade_fifo"
#define CLIENT_ALL_FIFO_NAME "/tmp/client_fifo"
#define WATCH_FIFO "/tmp/watch_fifo"
#define CLIENT_TEST_DEAD_FIFO_NAME "/tmp/client_test_dead_fifo"

/***** queue_x.xml ******/
const short QUEUE_START_INDEX = 1;
const short QUEUE_END_INDEX = 2;

/* BTSetting*/
const short SIMULANEITY_TASK_SIZE = 2;	//同时下载的任务数目
const short  MAX_ACTIVER_TR  =  8;	//最大同时激活的任务限制
const short  MAX_SEED_HOUR  =  48;	//做种时间
const short  MAX_INACTIVE_TM  =  8;	//最大同时不激活激活的任务限制
const short  AUTO_DEL_FINISH = 1;	//自动删除完成任务


//#define TORRENT_SAVE_PATH "/tmp/a.torrent"
#define HARD_DISK_PATH "/tmp/hdd/volumes/HDD1/"
#define BT_SAVE_PATH "/tmp/hdd/volumes/HDD1/BT/"
#define BT_TORRENTS_SAVE_DIR "/tmp/hdd/volumes/HDD1/torrents/"

/***** Web Page ******/
#define JOB_XML_PATH "/tmp/bt_job_status"
#define SETTING_XML_PATH "/tmp/hdd/volumes/HDD1/SettingCGI.xml"

#define CMD_MAX 300

#define TR_SH_PATH "/opt/etc/transmission/trguard.sh"

#endif

