#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LOGFILE "audit.log"

int main(int argc, char *argv[]) {
	if(argc < 2) {
		char msg[] = "Usage:\n./auditlog --add \"message\"\n./auditlog --view\n";
		write(1,msg,strlen(msg));
		return 1;
	}
	
	if ( strcmp(argv[1],"--add")== 0 ) {
		int fd = open(LOGFILE,O_WRONLY | O_CREAT | O_APPEND,0644);
		if (fd == -1) {
			return 1;
		}
	
	if(argc<3){
		char msg[] = "Please provide a message.\n";
		write(1,msg,strlen(msg));
		close(fd);
		return 1;
	}
	write(fd,argv[2],strlen(argv[2]));
	write(fd,"\n",1);

	close(fd);

	}

if ( strcmp(argv[1],"--view")== 0 ) {
	int fd = open(LOGFILE,O_RDONLY);
	if(fd == -1) {
		return 1;
	}
	char ch;
	char linebuf[1024];
	int idx = 0;
	int line = 1;
	while (read(fd, &ch, 1) > 0) {
    linebuf[idx++] = ch;

    if (ch == '\n')
    {
        char num[20];
        int len = sprintf(num, "%d: ", line);

        write(1, num, len);
        write(1, linebuf, idx);

        idx = 0;
        line++;
    }
	}
	if (idx > 0)
{
    char num[20];
    int len = sprintf(num, "%d: ", line);

    write(1, num, len);
    write(1, linebuf, idx);
}
	close(fd);
}

	return 0;
}
