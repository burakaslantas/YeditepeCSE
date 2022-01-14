#include<stdio.h>

int difference(int x, int y)
{
    if( x > y )
        return x - y;
    else
        return y - x;
}

void getNumberAndCalculateDiff()
{
    int x,y;
    printf("enter two number: ");
    scanf("%d %d",&x,&y);
    printf("result: %d\n", difference(x,y));
}




int main()
{

    getNumberAndCalculateDiff();
    getNumberAndCalculateDiff();

    return 0;
}