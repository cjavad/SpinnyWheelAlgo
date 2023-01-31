using System;
using System.Linq;

public class MainClass {
    public static void Main() {
        int count = Int32.Parse(Console.ReadLine());
        int[] nums = Console.ReadLine().Split(' ').Select(
            delegate(string x) {
                return Int32.Parse(x);
            }
        ).ToArray();

        Console.WriteLine(findMax(nums));
    }

    public static int findMax(int[] numsInt) {      
        var max = 0;
        for (var i = 1; i < numsInt.Length;) {
            if (numsInt[i++] > numsInt[max]) max = i - 1;
        }
        return max;
    }
}