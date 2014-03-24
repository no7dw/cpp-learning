#include <unistd.h>
#include <fcntl.h>

int lock_reg(int fd, int cmd, int type, off_t offset , int whence, off_t len)
{
	struct flock lock;
	lock.l_type = type;
	lock.l_start = offset;
	lock.l_whence = whence;
	lock.l_len = len;

	return ( fcntl(fd, cmd, &lock));
}

pid_t lock_test(int fd, int type, off_t offset, int whence, off_t len)
{
	struct flock lock;
	lock.l_type = type;
	lock.l_start = offset;
   	lock.l_whence = whence;
   	lock.l_len = len;

	if(fcntl(fd, F_GETLK, &lock) == -1)
		return -1;
	
	if(lock.l_type == F_UNLCK)
		return 0;

	return lock.l_pid;

}

#define read_lock(fd, offset, whence, len) \
	lock_reg(fd, F_SETLK, F_RDLCK, offset, whence, len)
#define readw_lock(fd, offset, wheence, len) \
	lock_reg(fd, F_SETLKW, F_RDLCK, offset, whence, len)
#define write_lock(fd, offset, wheence, len) \
	lock_reg(fd, F_SETLK, F_WRLCK, offset, whence, len)
#define writew_lock(fd, offset, whence, len) \
	lock_reg(fd, F_SETLKW, F_WRLCK, offset, whence, len)
#define un_lock(fd, offset, whence, len) \
	lock_reg(fd, F_SETLK,F_UNLCK, offset, whence, len)
#define is_read_loackable(fd, offset, whence, len) \
	!lock_test(fd, F_RDLCK, offset, whence, len)
#define is_write_lockable(fd, offset, whence, len) \
	!lock_test(fd, F_WRLCK, offset, whence, len)
#define my_lock(fd) (writew_lock(fd, 0, SEEK_SET, 0) )
#define my_unlock(fd) (un_lock(fd, 0, SEEK_SET, 0))

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define SWQFILE "seqno"
#define MAX_LINE 300
#include <string.h>
int main(int argc, char **argv)
{
	int fd;
	long i= 0;long seqno = 0;
	pid_t pid;
	ssize_t n;
	char line[MAX_LINE+1];
	pid =getpid();
	fd = open(SWQFILE, O_RDWR, "ab" );
	for(i = 0 ; i< 20 ;i++ )
	{
		my_lock(fd);
		lseek(fd, 0L, SEEK_SET);
		n = read(fd, line, MAX_LINE);
		line[n] = '\0';
		n = sscanf(line,  "%ld\n" , &seqno);
		printf("%s: pid = %ld, seq# = %ld\n", argv[0], (long)pid, seqno);
		seqno++;
		snprintf(line, sizeof(line), "%ld\n",seqno);
		lseek(fd, 0L, SEEK_SET);
		write(fd, line, strlen(line));
		my_unlock(fd);
	}
	exit(0);

}
