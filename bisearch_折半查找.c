/*************************************************************************
	> File Name: 折半查找.c
	> Author:Yanzu 
	> Mail:ruiwang22@foxmail.com 
	> Created Time: Mon 30 Aug 2021 10:07:20 AM CST
 ************************************************************************/

#include<stdio.h>

int binary_search(int n, int m, int *num){
    int l = 0, r = n -1, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(num[mid] == m) return mid;
        if(num[mid] > m ) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main(){
    int n, k, m, i, j;
    int numbers[1000001];

    while(~scanf("%d%d", &n, &k)){
        //读入给定的数字
        for (i = 0; i < n; i++){
            scanf("%d",&numbers[i]);
        }

        for(j = 0; j < k; j++){
            //读入待查找的数字
            scanf("%d",&m);
            printf("%d",binary_search(n, m, numbers)+1);
            if(j < k-1) printf(" ");

        }
        printf("\n");
    }
    
    return 0;
}
