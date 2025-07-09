using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace acmp252
{
    public struct Volume
    {
        public double Weight;
        public string Unit;
        public Volume(double weight, string unit)
        {
            this.Weight = weight;
            this.Unit = unit;
        }
    }
    internal class Program
    {
        private static Dictionary<char, double> map = new Dictionary<char, double>() {
            { 'm', 1e-3 },
            { 'k', 1e3 },
            { 'M', 1e6 },
            { 'G', 1e9 },
            { 'g', 1 },
            { 'p', 16380 },
            { 't', 1e6 },
        };
        public static double toGramm(double weight, string unit)
        {
            foreach (char el in unit)
            {
                weight *= map[el];
            }
            return weight;
        }
        public static double toUnit(double weight, string unit)
        {
            foreach (char el in unit)
            {
                weight /= map[el];
            }
            return Math.Round(weight);
        }
        static void sort(Volume[] arr)
        {
            for (int i = 0; i < arr.Length; ++i)
            {
                for (int j = 0; j < arr.Length - i - 1; ++j)
                {
                    if (arr[j].Weight > arr[j + 1].Weight)
                    {
                        (arr[j], arr[j + 1]) = (arr[j + 1], arr[j]);
                    }
                }
            }
        }
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            string[] tokens;

            Volume[] volumes = new Volume[n];

            for (int i = 0; i < n; i++)
            {
                tokens = Console.ReadLine().Split();
                volumes[i] = new Volume(toGramm(double.Parse(tokens[0]) * 1000, tokens[1]), tokens[1]);
            }

            sort(volumes);

            foreach (Volume volume in volumes)
            {
                Console.WriteLine($"{toUnit(volume.Weight, volume.Unit) / 1000} {volume.Unit}");
            }
        }
    }
}