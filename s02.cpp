#include <stdio.h>

const int DECIMAL = -87;

int main(void) {
	int x = DECIMAL;
	bool minus_flag = false;
	if (x < 0) {
		minus_flag = true;
		x *= (-1);
	}
	const size_t BIT_LENGTH = sizeof(DECIMAL) * 8;
	int a[BIT_LENGTH];

	int i = 0;
	for (; i < BIT_LENGTH; i++) {
		a[i] = x % 2;
		x /= 2;
		if (x == 0) {
			break;
		}
	}

	if (minus_flag) {
		printf("-");
	}
	for (; i >= 0; i--) {
		printf("%d", a[i]);
	}
	printf("\n");

	return 0;
}
