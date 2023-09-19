using System.IO.Pipes;

namespace leetcode
{
    public class MinStack
    {
        private List<int> min;
        private List<int> stack;
        private int ind;
        public MinStack()
        {
            min = new List<int>();
            stack = new List<int>();
            ind = -1;
        }

        public void Push(int val)
        {
            ++ind;
            if (stack.Count <= ind)
            {
                stack.Add(val);
                min.Add(0);
            }
            stack[ind] = val;
            min[ind] = ind == 0 ? val : Math.Min(val, min[ind - 1]);
        }

        public void Pop()
        {
            --ind;
        }

        public int Top()
        {
            return stack[ind];
        }

        public int GetMin()
        {
            return min[ind];
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            MinStack obj = new MinStack();
            obj.Push(5);
            obj.Push(2);
            obj.Push(3);
            obj.Pop();
            int param_3 = obj.Top();
            int param_4 = obj.GetMin();
            Console.WriteLine(param_3);
            Console.WriteLine(param_4);
        }
    }
}