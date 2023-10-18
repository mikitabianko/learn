using System.Diagnostics.SymbolStore;
using System.Runtime.InteropServices.Marshalling;

namespace leetcode_227_c_
{
    public class Solution
    {
        public int Calculate(string s)
        {
            Stack<int> st = new Stack<int>();

            int num = 0;
            char sign = '+';

            for (int i = 0; i < s.Length; ++i)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                }
                if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' || i == s.Length - 1) 
                {
                    if (sign == '+')
                    {
                        st.Push(num);
                    }
                    else if (sign == '-')
                    {
                        st.Push(-num);
                    }
                    else if (sign == '*')
                    {
                        st.Push(num * st.Pop());
                    }
                    else if (sign == '/')
                    {
                        st.Push(st.Pop() / num);
                    }
                    sign = s[i];
                    num = 0;
                }
            }

            int ans = 0;

            while (st.Count > 0)
            {
                ans += st.Pop();
            }

            return ans;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Calculate("2+2*2"));     // 6
            Console.WriteLine(solution.Calculate("3+2*2"));     // 7
            Console.WriteLine(solution.Calculate(" 3/2 "));     // 1
            Console.WriteLine(solution.Calculate(" 3+5 / 2 ")); // 5
        }
    }
}