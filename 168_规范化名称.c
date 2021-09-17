/*************************************************************************
	> File Name: 168.规范化名字.c
	> Author:Yanzu 
	> Mail:ruiwang22@foxmail.com 
	> Created Time: Fri 17 Sep 2021 01:21:26 PM CST
 ************************************************************************/
//题目描述
//一个名单里面有大型机械的很多零部件名，但是由于制作这个名单的人习惯不太好，零部件的名称的大小写很混乱。有的是大写字母开头，有些是小写字母开头，零部件名称中间的字符也是大小写混乱。
//
//请你设计程序，将名单上零部件的名称都变为开头字母大写，后面字母全小写的形式.
#include<stdio.h>
#include<string.h>

void letter(char *a ){
    int i=0;

    while(a[i]){
    if(a[0] >= 'a' && a[0] <= 'z')
    a[0] -= 32;

    i++;
    if(a[i] >= 'A' && a[i] <= 'Z')
    a[i] += 32;
    }
}

void swap(char *a, char *b){
    char temp[100] = {0};
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int main(){
    int i,n;
    char a[100][100] = { 0 };
    scanf("%d\n",&n);
    for(i = 0; i < n; i++){
        scanf("%s\n",a[i]);
    }

    for(i = 0; i < n; i++){
        letter(a[i]);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(a[i],a[j]) > 0)
            swap(a[i],a[j]);
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s\n",a[i]);
    }

    return 0;
}
