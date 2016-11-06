//4-1. https://pta.patest.cn/pta/test/15/exam/3/question/724
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Read()
{
    int len;
    int num;
    scanf("%d",&len);
    List list=NULL;
    List last=NULL;
    if(len==0)
        return NULL;
    scanf("%d",&num);
    list=(List)malloc(sizeof(struct Node));
    list->Data=num;
    list->Next=NULL;
    last=list;
    len--;
    while(len)
    {
        scanf("%d",&num);
        List node = (List) malloc(sizeof(struct Node));
        node->Data=num;
        node->Next=NULL;
        last->Next=node;
        last=node;
        len--;
    }
    return list;
}

void Print(List L)
{
    if(L==NULL){
        return;
    }
    List last=L;

    while(last!=NULL)
    {
        printf("%d ",last->Data);
        last=last->Next;
    }
    printf("\n");

}

List Reverse(List L)
{
    if(L==NULL)
        return NULL;
    PtrToNode listre=NULL;
    PtrToNode t = L->Next;
    if(t==NULL)
    {
        listre=L;
        return listre;
    }
    L->Next=t->Next;
    listre=t;
    t->Next=L;

    while(L->Next!=NULL)
    {
        t=L->Next;
        L->Next=t->Next;
        t->Next=listre;
        listre=t;
    }
    return listre;
}
