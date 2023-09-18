namespace leetcode
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }
    public class Solution
    {
        public bool IsPalindrome(ListNode head)
        {
            var stack = new Stack<ListNode>();
            var tmp = head;

            while (tmp != null)
            {
                stack.Push(tmp);
                tmp = tmp.next;
            }
            tmp = head;
            while (tmp != null)
            {
                if (tmp.val != stack.Peek().val)
                {
                    return false;
                }
                stack.Pop();
                tmp = tmp.next;
            }
            return true;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
            var solution = new Solution();
            Console.WriteLine(solution.IsPalindrome(head));
        }
    }
}