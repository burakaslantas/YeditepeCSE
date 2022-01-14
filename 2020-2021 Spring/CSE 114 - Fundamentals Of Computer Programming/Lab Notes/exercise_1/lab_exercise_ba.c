#include <stdio.h>

double CalculateA(int age)
{
    if (age < 12)
    {
        return 30;
    }
    if (age < 60)
    {
        return 40;
    }
    return 35;
}

double CalculateB(int age)
{
    if (age < 12)
    {
        return (2 * CalculateA(age));
    }
    if (age < 60)
    {
        return (4 * CalculateA(age));
    }
    return (3 * CalculateA(age));
}

double CalculateC(int age, char gender)
{
    if (gender == 'M')
    {
        double k;
        k = (CalculateA(age) / 2);
        if (age < 12)
        {
            return (20 + CalculateB(age) - (1.5 * k));
        }
        if (age < 60)
        {
            return (40 + (2 * CalculateB(age)) - (3 * k));
        }
        return (30 + CalculateB(age) - (2.5 * k));
    }
    double k;
    k = CalculateA(age) / 3;
    if (age < 12)
    {
        return (20 + CalculateB(age) - (1.5 * k));
    }
    if (age < 60)
    {
        return (40 + (2 * CalculateB(age)) - (3 * k));
    }
    return (30 + CalculateB(age) - (2.5 * k));
}

int main()
{
    int age;
    char gender;
    scanf("%d %c", &age, &gender);
    printf("%f %f %f", CalculateA(age), CalculateB(age), CalculateC(age, gender));
    return 0;
}
