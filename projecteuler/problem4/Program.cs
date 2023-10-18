//projecteuler.net/problem=4

bool IsPalindrom(int n)
{
    var nums = new List<int>(); 
    while(n > 0)
    {
        nums.Add(n % 10);
        n /= 10;
    }
    for (int i = 0; i < nums.Count; ++i)
    {
        if (nums[i] != nums[nums.Count - i - 1])
        {
            return false;
        }
    }
    return true;
}

var max = 0;

for(int i = 999; i > 99; --i)
{
    for (int j = 999; j > 99; --j)
    {
        if (IsPalindrom(i * j))
        {
            max = Math.Max(max, i * j);
        }
    }
}

Console.WriteLine(max); // 906609