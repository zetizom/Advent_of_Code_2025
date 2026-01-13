#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp = fopen("AoC_3.txt", "r"); 
    
    if(fp == NULL) {
        printf("파일 읽기 실패\n");
        return 1;
    }
    char str[120];
    int result = 0;

    while(fgets(str, sizeof(str), fp) != NULL) {
        char start = str[0];
        char end = str[1];
        int max = 0;
        if (start == '\n') {
            continue;
        }

        for(int i = 0; str[i] != '\0'; i++) {
            for (int j = i+1; str[j] != '\0'; j++) {
                start = str[i];
                end = str[j];
                int num = 10* (start - 48) + (end - 48);
                if (num > max) {
                    max = num;
                }
            }
        } 

        result += max;
        printf("%d, %d\n", max, result);

    }

    printf("%d\n", result);
    getchar();
}
