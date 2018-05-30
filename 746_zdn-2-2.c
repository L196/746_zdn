#include <stdio.h>
#include <math.h>

int main()
{
    int i, n, y;
    double x;
    printf("Kol-vo chisel=");
    scanf("%d", &n);
    for(i=1; i<=n; i+=1)
    {
	scanf("%lf", &x);
	y+=(pow((-1), i+1)*pow(x, 3));
    }
    printf("%d\n", y);
    return 0;
}
