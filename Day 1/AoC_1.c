#include<stdio.h>

int main() {
	FILE *fp = fopen("AoC_1.txt", "r");
	int num = 50;
	int count = 0;
	char a;
	int b;
	
	if (fp == NULL) {
		printf("파일 열기 실패\n");
	}
	
	char buffer[100];
	
	while (fscanf(fp, " %c%d", &a, &b) != EOF) {
		if (a == 'L') {
			num -= b;
			while (num < 0) {
				num += 100;
			}
			num = num % 100;
			if (num == 0) {
				count += 1;
			}
		} 
		else if ( a == 'R') {
			num += b;
			if (num > 99) {
				num = num % 100;
			}
			if (num == 0) {
				count += 1;
			}
		}			
	}
	printf("%d\n", count);
	fclose(fp);
	return 0;
}

		