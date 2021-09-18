/*
顺序表， 增删改查都具备
第一行输入数字，总操作数
第二行开始 第一个数字是模式，1是增加，后面接增加的节点和增加的值，2是删除，后面接删除的节点，3是查找，后面接查找的数字，4是遍历操作，后面不接数字
*/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size, length;
    int* data;

} Vector;

void init(Vector * Vector, int size) {
    Vector->size = size;
    Vector->length = 0;
    Vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector * Vector) {
    int *old_data = Vector->data;
    Vector->size = Vector->size * 2;
    Vector->data = (int *)malloc(sizeof(int) * Vector->size);
    for(int i = 0; i < Vector->length; ++i){
        Vector->data[i] = old_data[i];
    }
    free(old_data);
}

int insert(Vector * Vector,int loc, int num) {
    if(loc < 0 || loc > Vector->length){
        printf("failed\n");
        return ERROR;
    }
    if(Vector->length >= Vector->size){
        expand(Vector);
    }

    for(int i = Vector->length; i > loc ; --i){
        Vector->data[i] = Vector->data[i-1];
    }

    Vector->data[loc] = num;
    Vector->length++;
    printf("success\n");
    return OK;
}

int search(Vector * Vector, int value) {
    for(int i = 0; i < Vector->length; ++i){
        if(Vector->data[i] == value){
            printf("success\n");
            return i;
        }
    }
    printf("failed\n");
    return -1;
}

int delete_node(Vector * Vector,int num) {
    if(num < 0 || num >= Vector->length){
        printf("failed\n");
        return ERROR;
    }
    for(int i = num + 1; i < Vector->length; ++i){
        Vector->data[i-1] = Vector->data[i];
    }
    Vector->length = Vector->length - 1;
    printf("success\n");
    return OK;

}

void print(Vector * Vector) {
    for(int i = 0; i < Vector->length; ++i){
        if( i > 0){
            printf(" ");
        }
        printf("%d",Vector->data[i]);
    }
    printf("\n");
}

void clear(Vector * Vector) {
    free(Vector->data);
    free(Vector);

}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    int n,mode,loc, value;
    scanf("%d\n",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d ",&mode);
        switch(mode){
            case 1:
            scanf("%d %d",&loc, &value);
            insert(a,loc,value);
            break;
            case 2:
            scanf("%d",&loc);
            delete_node(a,loc);
            break;
            case 3:
            scanf("%d",&value);
            search(a,value);
            break;
            case 4:
            print(a);
            break;
        }
    }
    clear(a);
    return 0;
}
