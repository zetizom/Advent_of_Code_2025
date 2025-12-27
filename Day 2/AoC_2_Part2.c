#include<stdio.h>
#include<string.h>
#include<math.h>

int main() {
	FILE *fp = fopen("AoC_2.txt", "r");
	
	if (fp == NULL) {
		printf("파일 읽기 실패\n");
		return 1;
	}
	
	long long result = 0;
	char comma;
	long long start, end;
	while( fscanf(fp, "%lld-%lld", &start, &end) != EOF) {
		fscanf(fp, "%c", &comma);
		printf("%lld-%lld\n", start, end);
		for(start; start <= end; start++) {
			long long num = start;
			char str[20];
			sprintf(str, "%lld", num);
			int len = strlen(str);
			int i = 0;
			
			for(int i = 1; i <= len / 2; i++) {
    
				// 힌트 1: 나누기가 아니라 나머지(%)로 나누어 떨어지는지 확인
				if (len % i == 0) {
        
					int is_pattern = 1; // "일단 맞다고 가정" (플래그 변수)
        
					// 문자열 전체를 돌면서 확인
					for (int j = 0; j < len; j++) {
					// [핵심] 현재 글자가 패턴의 해당 위치 글자와 다르면?
						if (str[j] != str[j % i]) { 
						is_pattern = 0; // "어? 다르네. 패턴 아님."
						break; // 더 볼 필요 없음
						}
					}
        
					// 끝까지 검사했는데 is_pattern이 여전히 1이라면? -> 찾았다!
					if (is_pattern == 1) {
						result += num;
						break; // 문제 조건: "하나라도 찾으면 유효하지 않은 ID" -> 즉시 중단
					}					
				}
			}			
		}
	}
	
	printf("%lld\n", result);
	fclose(fp);
	return 0;
}

