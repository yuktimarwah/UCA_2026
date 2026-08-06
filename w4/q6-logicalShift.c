#include <stdio.h>

int logicalShift (int x, int n) {
	int mask = ~(((1<<31)>>n)<<1);
	return mask & (x>>n);
}

int main() {
	 int x, n;

	 printf("Enter number of bits to shift: ");
	 scanf("%x", &x);
	 
	 printf("Enter byte number : ");
	 scanf("%d", &n);

    printf("Result %d = 0x%X\n", n, logicalShift(x, n));

    return 0;
}
