using System.Collections.Generic;
using System.IO.Pipes;

namespace leetcode_173_c_
{
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public class BSTIterator
    {
        private Stack<TreeNode> stack;
        private void setLeft(TreeNode root)
        {
            var tmp = root;
            while (tmp != null)
            {
                stack.Push(tmp);
                tmp = tmp.left;
            }
        }
        public BSTIterator(TreeNode root)
        {
            stack = new Stack<TreeNode>();
            setLeft(root);
        }

        public int Next()
        {
            var tmp = stack.Pop();
            setLeft(tmp.right);
            return tmp.val;
        }

        public bool HasNext()
        {
            return stack.Count > 0;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            var root = new TreeNode(7, new TreeNode(3, new TreeNode(2)), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
            BSTIterator obj = new BSTIterator(root);
            int param_1 = obj.Next();
            int param_3 = obj.Next();
            int param_4 = obj.Next();
            int param_5 = obj.Next();
            int param_6 = obj.Next();
            int param_7 = obj.Next();
            bool param_2 = obj.HasNext();
            Console.WriteLine(param_7);
            Console.WriteLine(param_2);
        }
    }
}