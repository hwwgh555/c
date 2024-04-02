#include <stdio.h>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int x[n][m];
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &x[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", x[i][j]);
		}
	}
	
	return 0;
}
