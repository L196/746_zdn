#include <stdio.h>
#include <stdlib.h>

void HeapSter(int *, int);

int main()
{
    int i, n;
    int *a;

    scanf("%d", &n);
    a=(int *) malloc(n*sizeof(int));
    for(i=0; i<n; ++i)
    {
	scanf("%d", &a[i]);
    }
    HeapSter(a, n);
    for(i=0; i<n; ++i)
    {
	printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
    a=NULL;
    return 0;
}

void HeapSter(int *a, int n)
{
    if(n==1) return;
    int i, b, m=n;
    n=n/2-1;
    for(i=n; i>=0; --i)
    {
	if((a[i*2+1]>a[i])||(a[i*2+2]>a[i]))
	{
	    if((a[i*2+2]>a[i*2+1])&&((i*2+2)!=m))
	    {
		b=a[i*2+2];
		a[i*2+2]=a[i];
		a[i]=b;
	    }
	    else
	    {
		if(a[i*2+1]>a[i])
		{
                    b=a[i*2+1];
                    a[i*2+1]=a[i];
                    a[i]=b;
		}
	    }
	}
    }
    b=a[0];
    a[0]=a[m-1];
    a[m-1]=b;
    HeapSter(a, m-1);
}
