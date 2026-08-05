#include <stdio.h>
 
int sign(int x){
	return (x>>31) | (!!x);
}

int main() {
        int x;

        printf("Enter an integer: ");
        scanf("%d", &x);

        int result = sign(x);

        printf("bitXor(%d) = %d\n", x,  result);

        return 0;
}
