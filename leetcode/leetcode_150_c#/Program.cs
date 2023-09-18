namespace leetcode
{
    public class Solution
    {
        public int EvalRPN(string[] tokens)
        {
            var stack = new Stack<int>();
            
            foreach (var token in tokens)
            {
                switch (token)
                {
                    case "+":
                        stack.Push(stack.Pop() + stack.Pop());
                        break;
                    case "-":
                        int tmp = stack.Pop();
                        stack.Push(stack.Pop() - tmp);
                        break;
                    case "*":
                        stack.Push(stack.Pop() * stack.Pop());
                        break;
                    case "/":
                        tmp = stack.Pop();
                        stack.Push(stack.Pop() / tmp);
                        break;
                    default:
                        stack.Push(Int32.Parse(token));
                        break;
                }
            }
            return stack.Peek();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string[] tokens = { "4", "3", "-" };
            var solution = new Solution();
            Console.WriteLine(solution.EvalRPN(tokens));
        }
    }
}