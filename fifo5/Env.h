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
#define QUEUE_START_INDEX 1
#define QUEUE_END_INDEX 2

//#define TORRENT_SAVE_PATH "/tmp/a.torrent"
#define HARD_DISK_PATH "/tmp/hdd/volumes/HDD1/"
#define BT_SAVE_PATH "/tmp/hdd/volumes/HDD1/BT/"
#define BT_TORRENTS_SAVE_DIR "/tmp/hdd/volumes/HDD1/torrents/"

/***** Web Page ******/
#define JOB_XML_PATH "/tmp/bt_job_status"
#define SETTING_XML_PATH "/tmp/hdd/volumes/HDD1/SettingCGI.xml"

/***** XML ******/
#define FINISH_JOBS_RECORD_FILE "/tmp/hdd/volumes/HDD1/finish_list.xml"

/***** Sort ******/
//#define COURSE_INFO_PATH "/tmp/hdd/volumes/HDD1/LGSystem/STXD/CourseInfo7.xml"
#define AVT_DIRPATH "/tmp/hdd/volumes/HDD1/LGSystem/STXD/" //视听选答的资源的磁盘路径
#define VP_DIRPATH "/tmp/hdd/volumes/HDD1/LGSystem/KTXDC/"//看图学单词的资源的磁盘路径
#define LS_DIRPATH "/tmp/hdd/volumes/HDD1/LGSystem/SQLD/"//抒情朗读的资源的磁盘路径

#define QUEUE_START_INDEX 1
#define QUEUE_END_INDEX 2

#endif
