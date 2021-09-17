/*输入格式
第一行输入一个整数 
（
）
，表示一共有  个插入操作。

接下来输入  行，每行输入两个整数  ，
（
）
， 代表元素插入顺序表的位置， 代表插入元素的值，之间用一个空格隔开。

输出格式
输出若干行，对应每一个插入操作。如果一个元素正确插入到顺序表中后，程序输出 success，否则输出 failed。如果插入过程中有执行了扩容操作，程序需要额外输出 expand。
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int length,size;
    int *data;

} Vector;

void init(Vector * Vector, int size) {
     Vector->size = size;
     Vector->length = 0;
     Vector->data = (int *)malloc(sizeof(int)* size);
}

void expand(Vector * Vector) {
    int * old_data = Vector->data;
    Vector->size = Vector->size * 2;
    Vector->data = (int *)malloc(sizeof(int)* Vector->size);
    for(int i = 0; i < Vector->length; ++i){
        Vector->data[i] =old_data[i]; 
    }
    free(old_data);

}

int insert(Vector * Vector, int loc, int value) {
    if(loc < 0 || loc > Vector->length){
        printf("failed\n");
        return ERROR;
    }else{
    if(Vector->length >= Vector->size){
        expand(Vector);
        printf("expand\n");
    }
    
    for(int i = Vector->length; i > loc; --i ){
        Vector->data[i] = Vector->data[i-1];
       
    }
     Vector->data[loc] = value;
        Vector->length++;
        printf("success\n");
        return OK;
    }

}


void clear(Vector * Vector) {
    free(Vector->data);
    free(Vector);

}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    int n;
    scanf("%d",&n);
    init(a, 5);
    int loc[n],value[n];
    for(int i =0 ; i < n; ++i){
        scanf("%d %d",&loc[i],&value[i]);
    }
    for(int i=0; i < n; ++i){
        insert(a ,loc[i], value[i]);
    }


    clear(a);

    return 0;
}