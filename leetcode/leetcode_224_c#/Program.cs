using System.Text.RegularExpressions;

namespace leetcode_224_c_
{
    public class Solution
    {
        public int Calculate(string s)
        {
            int ans = 0;
            int sign = 1;
            int num = 0;

            var stack = new Stack<int>();

            stack.Push(sign); 

            foreach (var el in s)
            {
                if (el <= '9' && el >= '0')
                {
                    num = num * 10 + ((int)el - '0');
                }
                else if (el == '(')
                {
                    stack.Push(sign);
                }
                else if (el == ')')
                {
                    stack.Pop();
                }
                else if (el == '+' || el == '-')
                {
                    ans += sign * num; 
                    sign = (el == '-' ? -1 : 1) * stack.Peek();
                    num = 0;
                }
            }
            return ans + sign * num;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Calculate("1 + 1")); // 2
            Console.WriteLine(solution.Calculate(" 2-1 + 2 ")); // 3
            Console.WriteLine(solution.Calculate("(1+(4+5+2)-3)+(6+8)")); // 23
            Console.WriteLine(solution.Calculate("1 + 1 -5 + 23 - (5 + 3)")); // 12
            Console.WriteLine(solution.Calculate("1-(     -2)")); // 3
        }
    }
}