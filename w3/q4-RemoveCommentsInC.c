#include <stdio.h>

int main() {
    int ch, next;

    while ((ch = getchar()) != EOF) {

        // Handle string literals
        if (ch == '"') {
            putchar(ch);
            while ((ch = getchar()) != EOF) {
                putchar(ch);
                if (ch == '\\') {          // Escape sequence
                    ch = getchar();
                    if (ch != EOF)
                        putchar(ch);
                } else if (ch == '"') {
                    break;
                }
            }
        }

        // Handle character constants
        else if (ch == '\'') {
            putchar(ch);
            while ((ch = getchar()) != EOF) {
                putchar(ch);
                if (ch == '\\') {          // Escape sequence
                    ch = getchar();
                    if (ch != EOF)
                        putchar(ch);
                } else if (ch == '\'') {
                    break;
                }
            }
        }

        // Possible comment
        else if (ch == '/') {
            next = getchar();

            // Single-line comment
            if (next == '/') {
                while ((ch = getchar()) != EOF && ch != '\n');
                if (ch == '\n')
                    putchar('\n');
            }

            // Multi-line comment
            else if (next == '*') {
                int prev = 0;
                while ((ch = getchar()) != EOF) {
                    if (prev == '*' && ch == '/')
                        break;
                    prev = ch;
                }
            }

            // Not a comment
            else {
                putchar(ch);
                if (next != EOF)
                    putchar(next);
            }
        }

        // Normal character
        else {
            putchar(ch);
        }
    }

    return 0;
}
