#include <stdio.h>

int my_strlen(const char *str) {
	int count = 0;

	while (str[count] != '\0') {
		count++;
	}

	return count;

}

int main() {
	char str[] = "Hello";

	int length = my_strlen(str);

	printf("Length = %d\n", length);

	return 0;
}
