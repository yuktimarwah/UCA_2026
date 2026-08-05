#include <stdio.h>

int getByte(int x, int n) {
	return (x>>(n<<3))&0xFF;
}

int main() {
	 int x, n;

    printf("Enter a hexadecimal number (e.g., 12345678): ");
    scanf("%x", &x);

    printf("Enter byte number (0-3): ");
    scanf("%d", &n);

    printf("Byte %d = 0x%X\n", n, getByte(x, n));

    return 0;
}
