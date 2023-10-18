//projecteuler.net/problem=5

long GCD(long a, long b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a + b;
}

long ans = 1;

for (int i = 1; i < 20; ++i)
{
    ans = ans / GCD(ans, i) * i;
}

Console.WriteLine(ans); //232792560