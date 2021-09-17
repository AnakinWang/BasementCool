/*************************************************************************
	> File Name: 169.密码翻译.c
	> Author:Yanzu 
	> Mail:ruiwang22@foxmail.com 
	> Created Time: Fri 17 Sep 2021 01:52:46 PM CST
 ************************************************************************/
//输入
//输入第一行只有一个正整数N ，表示密码字符串中可能出现的不同大写字母的个数，其中（1≤N≤26）。
//
//之后的2N行：表示密码字典，每两行代表一个大写字母的信息：其中第一行为一个大写字母，第二行为这个大写字母对应的正整数（不大于1000 ）。
//
//最后一行：是密码（一个只含有字母的字符串，其长度不超过 30 ）。
//
//输出
//输出只含有一个自然数表示开门的密码（小于 30000 ）。
#include<stdio.h>

int main(){
    int n;
    char letter[26];
    int num[1000] = {0};
    char str[30];
    int res = 0;

    scanf("%d\n",&n);
    for(int i = 0; i< n; i++){
        scanf("%c\n",&letter[i]);
        scanf("%d\n",&num[i]);
    }
    scanf("%s",&str);

    for(int i = 0; i < strlen(str); i++){
        for(int j = 0; j < strlen(letter); j++ ){
            if(str[i] == letter[j]){
                res += num[j];
            }
        }
    }

    printf("%d\n",res);
    
    return 0;
}
