public class Solution
{
    public int CompareVersion(string v1, string v2)
    {
        string[] a1 = v1.Split('.');
        string[] a2 = v2.Split('.');
        int n1 = a1.Length, n2 = a2.Length;
        int maxLen = Math.Max(n1, n2);

        for (int i = 0; i < maxLen; i++)
        {
            int num1 = i < n1 ? int.Parse(a1[i]) : 0;
            int num2 = i < n2 ? int.Parse(a2[i]) : 0;

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }

        return 0;
    }
}
