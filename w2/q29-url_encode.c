#include <stdio.h>

void url_encode(char *str, int true_length) {
	int spaces = 0;

	for (int i = 0; i < true_length; i++) {
		if (str[i] == ' ') {
			spaces++;
		}
	}

	int new_length = true_length + spaces * 2;

	str[new_length] = '\0';

	for (int i = true_length - 1, j = new_length - 1; i >= 0; i--) {

		if (str[i] == ' ') {
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else {
			str[j--] = str[i];
		}
	}
}

int main () {
	char str[20] = "Hello world ";
	
	url_encode(str, 12);

	printf("%s\n", str);

	return 0;
}
