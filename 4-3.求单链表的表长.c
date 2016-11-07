#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/* 你的代码将被嵌在这里 */
List Read()
{
	int num=0;
	List first=(List)malloc(sizeof(struct LNode));
	List last=first;
	scanf("%d",&num);
	first->Data=num;
	first->Next=NULL;
	while(scanf("%d",&num)!=EOF&&(num+1))
	{
		List T=(List)malloc(sizeof(struct LNode));
		last->Next=T;
		last=T;
		T->Data=num;
		T->Next=NULL;
	}
	return first;
	
	
}
int Length(List L)
{
	if(L==NULL)
		return 0;
	else 
	{
		int length=1;
		while(L->Next)
		{
			length++;
			L=L->Next;
		}
		return length;
	}
			
		
}