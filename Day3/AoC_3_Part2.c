#include<stdio.h>

int main() {
    FILE *fp = fopen("AoC_3.txt", "r"); 

    if (fp == NULL) {
        printf("파일 읽기 실패\n");
    }
    
    char str[120];
    while(fgets(str, sizeof(str), fp) != NULL) {
        for(int i = 0; i != '\0'; i++) {
            printf("%s", str[i]);
        }
        printf("\n");
    }

}