/*************************************************************************
    > File Name: 字符串2.c
    > Author:Yanzu 
    > Mail:ruiwang22@foxmail.com 
    > Created Time: Fri 17 Sep 2021 12:40:13 PM CST
 ************************************************************************/
//第一行输入字符串a
//第二行输入插入的位置n
//第三行输入字符串b
//第一行输出字符串a的长度
//第二行输出字符串a中第一次遇到'a'的位置
//第三行输出插入字符串b之后的字符串c

#include<stdio.h>
#include<string.h>
int main(){
    char a[30000] = {0};
    char b[30000] = {0};
    char c[60000] = {0};

    int n=0;
    gets(a);

    scanf("%d\n",&n);

    scanf("%s",b);

    printf("%ld\n",strlen(a));
    for(int k = 0; k < strlen(a); k++){
        if( a[k]=='a'){
            printf("%d\n", k+1);
            break;
    }
    }

    for(int i = 0; i < n - 1; i++){
        c[i] = a[i];
    }

    for(int j = n - 1; j < n+strlen(b) -1; j++){
        c[j] = b[j-n+1];
    }

    for(int l = n + strlen(b)-1; l < strlen(a)+strlen(b); l++){
        c[l] = a[l - strlen(b)];
    }

    printf("%s\n",c);


    return 0;
}
