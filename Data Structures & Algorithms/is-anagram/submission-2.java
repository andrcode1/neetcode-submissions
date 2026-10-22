class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        int[] charCountS = new int[26];
        int[] charCountT = new int[26];

        for (int i = 0; i < s.length(); ++i) {
            char charS = s.charAt(i);
            char charT = t.charAt(i);

            charCountS[charS - 'a']++;
            charCountT[charT - 'a']++;
        }

        if (Arrays.equals(charCountS, charCountT)) {
            return true;
        }
        return false;
    }
}
