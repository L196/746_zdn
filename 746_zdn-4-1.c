#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int a;
    struct stack *next;
};

struct stack * init(void);
struct stack * push(struct stack *);
struct stack * pop(struct stack *);
void top(struct stack *);
void delstack(struct stack *);

int main()
{
    int n;
    struct stack *head;

    head=init();
    head=push(head);
    head=push(head);
    head=push(head);
    top(head);
    head=pop(head);
    top(head);
    delstack(head);
    head=NULL;
    return 0;
}

struct stack * init(void)
{
    struct stack *head;
    int n;

    scanf("%d", &n);
    head=(struct stack *) malloc(sizeof(struct stack));
    head->a=n;
    head->next=NULL;
    return head;
}

struct stack * push(struct stack *head)
{
    struct stack *p;
    int b;

    scanf("%d", &b);
    p=(struct stack *) malloc(sizeof(struct stack));
    p->a=b;
    p->next=head;
    head=p;
    p=NULL;
    return head;
}

struct stack * pop(struct stack *head)
{
    struct stack *p;
    int b;

    p=head;
    head=head->next;
    b=p->a;
    printf("%d\n", b);
    free(p);
    p=NULL;
    return head;
}

void top(struct stack *head)
{
    int b;

    b=head->a;
    printf("%d\n", b);
}

void delstack(struct stack *head)
{
    struct stack *p;
    int b;

    while(1)
    {
	b=head->a;
	printf("%d\n", b);
	if(head->next==NULL)
	{
	    free(head);
	    head=NULL;
	    break;
	}
	p=head;
	head=head->next;
	free(p);
	p=NULL;
    }
}
