class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagrams = new HashMap<>();

        for (String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            anagrams.computeIfAbsent(sorted, k -> new ArrayList<>()).add(s); 
        }

        List<List<String>> result = new ArrayList<>();
        result.addAll(anagrams.values());

        return result;
    }
}
