#include <stdio.h>

int p(int n) {
    if (n == 1) {
        printf("%d\n", n);
        return 1;
    }
    int val = p(n - 1) + 1;
    printf("%d\n", val);
    return val;
}
		
int main() {
    p(100);
        

    return 0;
}
