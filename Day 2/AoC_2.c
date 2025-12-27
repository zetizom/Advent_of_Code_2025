#include<stdio.h>
#include<string.h>
#include<math.h>

int main() {
	FILE *fp = fopen("AoC_2.txt", "r");
	long long start, end; 
	char comma;
	long long result = 0;
	
	if(fp == NULL) {
		printf("파일 읽기 실패\n");
		return 1;
	}
	
	while(fscanf(fp, "%lld-%lld", &start, &end) != EOF)  {
		printf("%lld-%lld\n", start, end);
		fscanf(fp ,"%c", &comma);
		for(start; start <= end; start++) {
			long long num = start;
			char str[20];
			sprintf(str ,"%lld", num); 
			int len = strlen(str);
			if((len % 2) == 0) {
				int c = len / 2;
				int n = pow(10, c);
				long long num1 = num / n;
				long long num2 = num % n;
				if (num1 == num2) {
				result += num;
				}
			}
		}
	}
	
	printf("%lld\n", result);
	fclose(fp);
	return 0;
}



