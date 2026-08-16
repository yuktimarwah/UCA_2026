#include <fcntl.h>
#include <unistd.h>


int main (int argc, char *argv[]) {

	int source_fd = open(argv[1], O_RDONLY);
	int desti_fd = open(argv[2], O_WRONLY | O_CREAT,0644);

	char buffer[1000];
	int n;

	while ((n = read(source_fd,buffer,1000))>0) {
		write(desti_fd, buffer, n);
	}

	close(source_fd);
	close(desti_fd);
}
