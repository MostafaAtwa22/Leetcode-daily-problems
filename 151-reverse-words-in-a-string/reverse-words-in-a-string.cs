public class Solution {
    public string ReverseWords(string s) {
        return string.Join(" ", s.Split(' ').Where (e => e != "").Reverse());
    }
}