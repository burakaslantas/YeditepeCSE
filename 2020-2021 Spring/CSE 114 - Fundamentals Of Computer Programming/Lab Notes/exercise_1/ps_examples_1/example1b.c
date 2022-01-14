#include<stdio.h>

int difference(int x, int y)
{
    if( x > y )
        return x - y;
    else
        return y - x;
}




void main()
{
    int x,y,result;
    printf("enter two number: ");
    scanf("%d %d",&x,&y);
    printf("result: %d", difference(x,y));

    printf("enter two number: ");
    scanf("%d %d",&x,&y);
    printf("result: %d",difference(x,y));
}
