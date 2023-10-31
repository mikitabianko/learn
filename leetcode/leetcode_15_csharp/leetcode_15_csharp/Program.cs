using System.Linq;

namespace leetcode_15_csharp;


class SequenceComparer<T> : IEqualityComparer<IEnumerable<T>>
{
    public bool Equals(IEnumerable<T> seq1, IEnumerable<T> seq2)
    {
        return seq1.SequenceEqual(seq2);
    }

    public int GetHashCode(IEnumerable<T> seq)
    {
        int hash = 1234567;
        foreach (T elem in seq)
            hash = unchecked(hash * 37 + elem.GetHashCode());
        return hash;
    }
}
public class Solution
{
    public IList<IList<int>> ThreeSum(int[] nums)
    {
        Array.Sort(nums);

        var ans = new HashSet<List<int>>(new SequenceComparer<int>());

        for (int i = 0; i < nums.Length - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int l = i + 1, r = nums.Length - 1;

            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0 && !ans.Contains(new List<int>{ nums[i], nums[l], nums[r] }))
                {
                    ans.Add(new List<int> { nums[i], nums[l], nums[r] });
                    ++l;
                    --r;
                    continue;
                }
                if (sum < 0)
                {
                    ++l;
                }
                else 
                {
                    --r;
                }
            }
        }
        
        return ans.ToList<IList<int>>();
    }
}
class Program
{
    static void Main(string[] args)
    {
        Solution solution = new Solution();

        var lists = solution.ThreeSum(new int[] { -2, 0, 0, 2, 2 });//{ -1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4 });

        foreach (var list in lists)
        {
            foreach (int element in list)
            {
                Console.Write($"{element} ");
            }
            Console.WriteLine();
        }
    }
}