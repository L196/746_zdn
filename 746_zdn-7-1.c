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
    step=n;
    while(step>=1)
    {
        step=step/1.247;
        for(i=0, j=step; j<n; ++i, ++j)
        {
	    if(a[i]>a[j])
	    {
	        b=a[i];
	        a[i]=a[j];
      	        a[j]=b;
	    }
        }
    }
    for(i=0; i<n; ++i) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
