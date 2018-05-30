#include <stdio.h>

int main()
{
    int n, i, k=0, x;
    printf("Kol-vo chisel=");
    scanf("%d", &n);
    for(i=1; i<=n; i+=1)
    {
	scanf("%d", &x);
	if(x>0)
	{
	    k+=1;
	}
    }
    printf("Polozh chisla=%d\n", k);
    return 0;
}
