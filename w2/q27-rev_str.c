#include <stdio.h>

void rev_str (char *str) {
	int l = 0;
	int r = 0;

	while (str[r] != '\0') {
		r++;
	}

	r--;

	while (l < r)
	{
		char temp = str[l];
		str[l] = str[r];
		str[r] = temp;

		l++;
		r--;
	}
}

int main() {
	char str[] = "Yukti";

	rev_str(str);

	printf("%s\n", str);

	return 0;
}
