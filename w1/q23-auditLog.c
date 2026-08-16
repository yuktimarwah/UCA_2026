#include <unistd.h>
#include <fcntl.h>

int add (char *argv) {

	int length = 0;
	while (argv[length] != '\0') {
		length++;
	}

	int fd = open("audit.log", O_WRONLY | O_CREAT | O_APPEND, 0644);

	write(fd, argv, length);
	write(fd, "\n", 1);

	close(fd);
	return 0;
}

void print_no(int num) {
    char digits[20];
    int i = 0;

    if (num == 0) {
        write(1, "0", 1);
        return;
    }

    while (num > 0) {
        digits[i] = (num % 10) + '0';
        num = num / 10;
        i++;
    }

    while (i > 0) {
        i--;
        write(1, &digits[i], 1);
    }
}

int view () {

	int fd = open("audit.log", O_RDONLY);

	char buffer[1000];

	int n;

	int line = 1;
	int new_line = 1;

	while ((n = read(fd, buffer, 1000)) > 0) {
			for (int i = 0; i < n; i++) {
			        if (new_line == 1) {
					print_no(line);
				     	write(1,": ", 2);
					new_line = 0;
				}

				char ch = buffer[i];
				write(1,&ch,1);
				if (buffer[i] == '\n' ) {
					line++;
					new_line = 1;
				}

			}
			}

	close(fd);
	return 0;
}

int main (int argc, char *argv[]) {

	if (argc == 3 && argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == 'a' && argv[1][3] == 'd' && argv[1][4] == 'd' && argv[1][5] == '\0') {
		return add(argv[2]);
	}

	if (argc == 2 && argv[1][0] == '-' &&
        argv[1][1] == '-' &&
        argv[1][2] == 'v' &&
        argv[1][3] == 'i' &&
        argv[1][4] == 'e' &&
        argv[1][5] == 'w' &&
        argv[1][6] == '\0') {
        return view();
    }
}
