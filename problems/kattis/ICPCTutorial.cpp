#include <cstdio>
#include <cmath>
using namespace std;
int m, n, t;
void fact() {
	long long int val = 1;
	for (int i = n; i >= 1; i--) {
		val *= i;
		if (val > m) {
			printf("TLE");
			return;
		}
	}
	printf("AC");
}

void pow_two() {
	long long int val = 1;
	for (int i = n; i >= 1; i--) {
		val *= 2;
		if (val > m) {
			printf("TLE");
			return;
		}
	}
	printf("AC");
}

void quad() {
	long long int val = 1;
	for (int i = 4; i >= 1; i--) {
		val *= n;
		if (val > m) {
			printf("TLE");
			return;
		}
	}
	printf("AC");
}

void cube() {
	long long int val = 1;
	for (int i = 3; i >= 1; i--) {
		val *= n;
		if (val > m) {
			printf("TLE");
			return;
		}
	}
	printf("AC");
}

void squ() {
	long long int val = 1;
	for (int i = 2; i >= 1; i--) {
		val *= n;
		if (val > m) {
			printf("TLE");
			return;
		}
	}
	printf("AC");
}

void n_log_n() {
	if (n > m || log2(n) * n > m) {
		printf("TLE");
	} else {
		printf("AC");
	}
}

void lin_n() {
	if (n > m) {
		printf("TLE");
	} else {
		printf("AC");
	}
}

int main() {
	scanf("%d %d %d", &m ,&n, &t);
	switch(t) {
	case 1:
		fact();
		break;
	case 2:
		pow_two();
		break;
	case 3:
		quad();
		break;
	case 4:
		cube();
		break;
	case 5:
		squ();
		break;
	case 6:
		n_log_n();
		break;
	case 7:
		lin_n();
		break;
	}
	return 0;
}
