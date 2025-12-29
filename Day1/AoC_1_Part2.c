#include<stdio.h>

int main() {
	FILE *fp = fopen("AoC_1.txt", "r");
	int num = 50;
	int count = 0; 
	char a;
	int b;
	
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return 1; 
	}
	
	
	while (fscanf(fp, " %c%d", &a, &b) != EOF) {
		int move = (a == 'R') ? 1 : -1;
		
		for(int i = 0; i < b; i++) {
			num = (num + 100 + move) % 100;
			
			if (num == 0) {
				++count;
			}
		}			
	}
			
	printf("%d\n", count);
	fclose(fp);
	return 0;
}
