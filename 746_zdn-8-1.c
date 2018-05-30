#include <stdio.h>
#include <stdlib.h>

void sort(int, int, int *);
void output(int *, int);

int main()
{
    int i, n;
    int *a;

    scanf("%d", &n);
    if(n==1) exit(1);
    a=(int *) malloc(n*sizeof(int));
    for(i=0; i<n; ++i)
    {
	scanf("%d", &a[i]);
    }
    sort(0, n-1, a);
    output(a, n);
    free(a);
    a=NULL;
    return 0;
}

void sort(int b, int e, int *a)
{
    int b1=b, e1=e, s;
    int m=(b1+e1)/2;
    int sup=a[m];
    while(b1<e1)
    {
	while(a[b1]<sup)
	    ++b1;

	while(a[e1]>sup)
	    --e1;

	if((b1<e1)&&((e1-b1)>1))
	{
	    s=a[b1];
	    a[b1]=a[e1];
	    a[e1]=s;
	}
	    else
	    {
		if(a[b1]>=a[e1])
		{
		    s=a[b1];
            	    a[b1]=a[e1];
            	    a[e1]=s;
		    break;
		}
	    }
    }
    if((b<b1)&&((b1-b)>1))
	sort(b, b1, a);
	else 
	{
	    if(a[b]>a[b1])
	    {	    
		s=a[b];
		a[b]=a[b1];
		a[b1]=s;
	    }
	}
    if((e1<e)&&((e-e1)>1))
	sort(e1, e, a);
	else
	{
	    if(a[e1]>a[e])
	    {
	        s=a[e];
                a[e]=a[e1];
        	a[e1]=s;
	    }
	}
}

void output(int *a, int n)
{
    for(int i=0; i<n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
