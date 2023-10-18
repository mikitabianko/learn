//projecteuler.net/problem=3

long n = 600851475143;

long ans = 0;

for (long i = 2; i <= n;)
{
    if (n % i == 0)
    {
        ans = i;
        n /= i;
    }
    else
    {
        ++i;
    }
}

Console.WriteLine(ans); // 6857