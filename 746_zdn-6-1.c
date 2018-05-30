#include<stdio.h>
#include<stdlib.h>

struct queue
{
    struct tree *t;
    struct queue *next;
};

struct queue * add(struct tree *, struct queue *);

struct tree
{
    int a;
    int k;
    struct tree *left;
    struct tree *right;
};

struct tree * init(int);
void tree(int, struct tree *);
void search(struct queue *, struct queue *);

int main()
{
    struct tree *head;
    int n, k, a, b, c;
    struct queue *headq=NULL, *tail=NULL;

    scanf("%d", &k);
    scanf("%d", &n);
    head=init(n);
    tree(k, head);
    tail=headq=add(head, tail);
    search(headq, tail);
    printf("\n");
    head=NULL;
    headq=NULL;
    tail=NULL;
    return 0;
}

struct tree * init(int n)
{
    struct tree *p;

    p=(struct tree *) malloc(sizeof(struct tree));
    p->k=n;
    scanf("%d", &n);
    p->a=n;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void tree(int k, struct tree *head)
{
    struct tree *p, *p1;
    int n1, n;

    for(int i=1; i<k; ++i)
    {
	n=head->k;
	p1=head;
	scanf("%d", &n1);
        p=init(n1);
	while(1)
	{
	    if(n1<n)
	    {
		if(p1->left==NULL)
		{
		    p1->left=p;
		    break;
		}
		    else
		    {
			p1=p1->left;
			n=p1->k;
			continue;
		    }
	    }
		else
		{
		    if(p1->right==NULL)
		    {
			p1->right=p;
			break;
		    }
			else
			{
			    p1=p1->right;
			    n=p1->k;
			    continue;
			}
		}
	}
    }

}

void search(struct queue *headq, struct queue *tail)
{
    struct queue *p;

    while(headq)
    {
	printf("%d ", headq->t->a);
        if(headq->t->left) tail=add(headq->t->left, tail);
        if(headq->t->right) tail=add(headq->t->right, tail);
	p=headq;
	headq=headq->next;
	free(p);
    }
}

struct queue * add (struct tree *h, struct queue *tail)
{
    struct queue *headq, *p;

    if(tail==NULL)
    {
	headq=(struct queue *) malloc(sizeof(struct queue));
	headq->t=h;
	headq->next=NULL;
	return headq;
    }
    p=(struct queue *) malloc(sizeof(struct queue));
    p->t=h;
    tail->next=p;
    tail=p;
    tail->next=NULL;
    p=NULL;
    return tail;
}
