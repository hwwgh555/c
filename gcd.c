#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0) return b;
	return gcd(b, a % b);
}


int main() {
	int m, n;
	scanf("%d%d", &m, &n);

	int answer;
	if (m >= n) {
		answer = gcd(m, n);
	} else {
		answer = gcd(n, m);
	}
	printf("%d", answer);
	return 0;
}
