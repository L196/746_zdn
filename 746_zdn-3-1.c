#include <stdio.h>
#include <stdlib.h>

struct spis
{
    int a;
    struct spis *next;  
    struct spis *prev;
};

struct spis * init(int);
struct spis * delelem(int, struct spis *);
struct spis * delelem2(int, struct spis *);
void delspis(struct spis *);
int inserta(int, int, struct spis *);
int insertb(int, int, struct spis *);
void outputspis(struct spis *);

int main()
{
    int n, k, a;
    struct spis *head;

    scanf("%d", &n);
    head=init(n);
    outputspis(head);
    scanf("%d", &k);
    head=delelem(k, head); 
    outputspis(head);
    scanf("%d", &k);
    head=delelem2(k, head);
    outputspis(head);
    scanf("%d", &a);
    scanf("%d", &k);
    inserta(a, k, head);
    outputspis(head);
    scanf("%d", &a);
    scanf("%d", &k);
    insertb(a, k, head);
    delspis(head);
    head==NULL;
    return 0;
}

struct spis * init(int n)
{
    int b;
    struct spis *head, *p, *p1;

    head=(struct spis*) malloc(sizeof(struct spis));
    scanf("%d", &b);
    head->a = b;
    head->next=NULL;
    head->prev=NULL;
    if(n==1) return head;
    p1=head;
    for(int i=1; i<n; i++)
    {
	p=(struct spis*) malloc(sizeof(struct spis));
	p1->next=p;
	p->prev=p1;
	p->next=NULL;
	scanf("%d", &b);
	p->a=b;
	p1=p;
    }
    p=NULL;
    p1=NULL;
    return (head);
}

struct spis * delelem(int k, struct spis *head)
{
    struct spis *p=head, *p1, *p2;
    int k1=0;

    while(1)
    {
	k1+=1;
	if(k1==k) break;
	if((p->next==NULL)&&(k1<k))
	{
	    return head;
	}
	p=p->next;
    }
    p1=p->prev;
    p2=p->next;
    free(p);
    p=NULL;
    if(p2!=NULL) p2->prev=p1;
    if(p1!=NULL) p1->next=p2;
	else head=p2;
    p1=NULL;
    p2=NULL;
    return head;
}

struct spis * delelem2(int k, struct spis *head)
{
    struct spis *p=head, *p1, *p2;

    while(1)
    {
	if(p->a==k) break;
	if(p->next==NULL)
	{
	    return head;
	}
        p=p->next;
    }
    p1=p->prev;
    p2=p->next;
    free(p);
    p=NULL;
    if(p2!=NULL) p2->prev=p1;
    if(p1!=NULL) p1->next=p2;
	else head=p2;
    p1=NULL;
    p2=NULL;
    return head;
}

void delspis(struct spis *head)
{
    int c;
    struct spis *p;

    while(1)
    {
        c=head->a;
        printf("%d ", c);
        p=head->next;
        free(head);
        head=p;
        if(head==NULL) break;
    }
    p=NULL;
    head=NULL;
    printf("\n");
}

int inserta(int a, int b, struct spis *head)
{
    int a1=0;
    struct spis *p;

    while(1)
    {
	a1+=1;
	if((head->next==NULL)&&(a1<=a))
	{
	    return 1;
	}
	if(a1==a) break;
	head=head->next;
    }
    p=(struct spis *) malloc(sizeof(struct spis));
    p->a=b;
    p->prev=head;
    p->next=head->next;
    head->next->prev=p;
    head->next=p;
    p=NULL;
    head=NULL;
    return 0;
}

void outputspis(struct spis *head)
{
    int c;

    while(1)
    {
        c=head->a;
        printf("%d ", c);
        head=head->next;
        if(head==NULL) break;
    }
    printf("\n");
}

int insertb(int c, int d, struct spis *head)
{
    int c1=0;
    struct spis *p;

    if(c==1)
    {
	return 1;
    }
    while(1)
    {
        c1+=1;
        if((head->next==NULL)&&(c1<c))
        {
            return 1;
        }
	if(c1==c) break;
        head=head->next;
    }
    p=(struct spis *) malloc(sizeof(struct spis));
    p->a=d;
    p->next=head;
    p->prev=head->prev;
    head->prev->next=p;
    head->prev=p;
    head=NULL;
    return 0;
}

