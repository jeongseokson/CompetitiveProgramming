#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
unsigned int calc_op(char *str, unsigned int base) {
	unsigned long long len = strlen(str), mult = 1, ans = 0;
	for (int i = len - 1; i >= 0; --i) {
		char c = str[i];
		unsigned long long val;
		if (c >= '0' && c <= '9')
			val = c - '0';
		else if (c >= 'a' && c <= 'z')
			val = c - 'a' + 10;
        if ((base != 1 && val >= base) || (base == 1 && val != 1))
            return 0;
		ans += val * mult;
		if (ans > UINT_MAX)
			return 0;
		mult *= base;
	}
	return ans;
}

unsigned int arith(unsigned int a, unsigned int b, char op) {
	unsigned long long ret;
	switch (op) {
	case '+':
        ret = a + b;
		break;
	case '-':
		if (b >= a)
			ret = 0;
		else
			ret = a - b;
		break;
    case '*':
        ret = a * b;
        break;
    case '/':
        if (b == 0 || a % b != 0)
            ret = 0;
        else
        	ret = a / b;
        break;
    default:
    	ret = 0;
    	break;
	}
	if (ret > UINT_MAX || ret <= 0)
		return 0;
	else
		return ret;
}

int main() {
	int cases;
	scanf("%d", &cases);
	char x[110], y[110], z[110], op;
	for (int i = 0; i < cases; ++i) {
		scanf("%s %c %s = %s", x, &op, y, z);
        bool inval = true;
		for (unsigned int b = 1; b <= 36; ++b) {
			unsigned int val_x = calc_op(x, b),
						val_y = calc_op(y, b),
						val_z = calc_op(z, b);
            if (!val_x || !val_y || !val_z)
                continue;
            unsigned int arith_val = arith(val_x, val_y, op);
            if (arith_val == val_z) {
                printf("%c", b < 10 ? b + '0' : (b == 36 ? '0' : (b - 10) + 'a'));
                inval = false;
            }

		}
        if (inval)
            printf("invalid");
        printf("\n");
	}
	return 0;
}
