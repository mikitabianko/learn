using System.Linq;
using System.Net.Http.Headers;

namespace leetcode_316_c_
{
    public class Solution
    {
        public string RemoveDuplicateLetters(string s)
        {
            int[] count = new int[128];
            bool[] used = new bool[128];

            List<char> ans = new List<char>();

            foreach (char c in s)
            {
                ++count[c];
            }

            foreach (char c in s)
            {
                --count[c];
                if (used[c])
                {
                    continue;
                }
                while (ans.Count > 0 && ans.Last() > c && count[ans.Last()] > 0)
                {
                    used[ans.Last()] = false;
                    ans.RemoveAt(ans.Count - 1);
                }
                used[c] = true;
                ans.Add(c);
            }
            return string.Join("", ans);
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();

            Console.WriteLine(s.RemoveDuplicateLetters("bcabc"));       // abc
            Console.WriteLine(s.RemoveDuplicateLetters("cbacdcbc"));    // acdb
        }
    }
}