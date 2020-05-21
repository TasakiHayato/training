#include <stdio.h>

int main(void) {

/* float型のデータサイズは32ビットなので、int型（32ビット整数型）およびchar型4個と共用体を構成 */

union { float f; int i; unsigned char c[4]; } a;

a.f = float(1.0);

/* 数値を表示 */

printf("10進表記 : %f\n", a.f);

printf("指数形式 : %e\n", a.f);

printf(" 8進表記 : %08X\n", a.i);

/* ビットの列を表示 */

printf(" 2進表記 : ");

for (int i = 31; i >= 0; i--) {

printf("%d", (a.i >> i) & 1);

}

printf("\n");

/* 符号部（ 1ビット ）、指数部（ 8ビット ）、仮数部（ 23ビット ）を表示 */

printf("符号部 : %X\n", (a.i >> 31) & 1);

printf("指数部 : %02X\n", (a.i >> 23) & 0xFF);

printf("仮数部 : %04X\n", a.i & 0x7FFFFF);

/* バイトオーダーを表示 */

printf("並び順 : ");

for (int i = 0; i < 4; i++) {

printf("%02X%c", a.c[i], (i < 3) ? ' ' : '\n');

}

return 0;

}