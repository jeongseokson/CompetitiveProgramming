#include <cstdio>
#include <cmath>

using namespace std;

int p, q, r, s, t, u;

double calc(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		double a = 0, b = 1;
		double val, x;
		while (fabs(b - a) > 1e-10) {
			x = (a + b) / 2;
			val = calc(x);
			if (val > 0)
				a = x;
			else
				b = x;
		}
		if (fabs(val) < 1e-5) {
			printf("%.4f\n", x);
		} else {
			printf("No solution\n");
		}
	}
	return 0;
}
