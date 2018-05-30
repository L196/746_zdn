#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int a;
    int k;
    struct tree *left;
    struct tree *right;
};

struct tree * init(int);
void tree(int, struct tree *);
void search(int, struct tree *);

int main()
{
    struct tree *head;
    int n, k, a, b, c;

    scanf("%d", &k);
    scanf("%d", &n);
    head=init(n);
    tree(k, head);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    search(a, head);
    search(b, head);
    search(c, head);
    head=NULL;
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

void search(int a, struct tree *head)
{
    int i=0;

    while(1)
    {
	if(a==(head->k))
	{
	    printf("%d %d\n", i, head->a);
	    return;
	}
	    else
	    {
		if(a<(head->k))
		{
		    if(head->left==NULL)
		    {
			printf("-1\n");
			return;
		    }
		    head=head->left;
		    i+=1;
		    continue;
		}
		    else
		    {
			if(head->right==NULL)
			{
			    printf("-1\n");
			    return;
			}
                        head=head->right;
                        i+=1;
                        continue;
	  	    }
	    }

    }
}
