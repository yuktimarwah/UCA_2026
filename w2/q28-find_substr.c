#include <stdio.h>

int find_substr (const char *haystack, const char *needle) {
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++) {

		j = 0;

		while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
			j++;
		}

		if (needle[j] == '\0') {
			return i;
		}
	}

	return -1;
}

int main() 
{
	char haystack[] = "Embedded Systems";
	char needle[] = "bed";

	int result = find_substr(haystack, needle);

	printf("%d\n", result);

	return 0;
}
