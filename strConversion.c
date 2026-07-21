#include <stdio.h>
#include <string.h>

void url_encode(char *str, int true_length) {
    int space_count = 0, i;

    // Count spaces in the true string
    for (i = 0; i < true_length; i++) {
        if (str[i] == ' ')
            space_count++;
    }

    // Calculate new length
    int index = true_length + space_count * 2;
    str[index] = '\0';

    // Traverse backwards
    for (i = true_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        } else {
            str[index - 1] = str[i];
            index--;
        }
    }
}

int main() {
    char str[100] = "Hello World    ";  // Extra buffer space
    int true_length = 11;

    url_encode(str, true_length);

    printf("Encoded String: %s\n", str);

    return 0;
}
