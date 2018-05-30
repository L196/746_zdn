#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n, step, b, k;
    int *a;

    scanf("%d", &n);
    if(n==1) exit(1);
    a=(int *) malloc(n*sizeof(int));
    for(i=0; i<n; ++i)
    {
	scanf("%d", &a[i]);
    }
    step=7;
    while(step>=1)
    {
        for(i=0; i<n-1-step; ++i)
        {
	    for(j=i, k=i+step; k<n; j+=step, k+=step)
	    {
		if(a[j]>a[k]) 
		{
		    b=a[j];
		    a[j]=a[k];
		    a[k]=b;
		}
	    }
        }
        step-=2;

    }
    for(i=0; i<n; ++i) printf("%d ", a[i]);
    printf("\n");
    free(a);
    a=NULL;
    return 0;
}
