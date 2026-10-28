class Solution {
    public boolean isValid(String s) {
        Map<Character, Character> neededBracket = Map.of(
            ')', '(',
            '}', '{',
            ']', '['
        );

        Deque<Character> openingBrackets = new ArrayDeque<>();
        for (char currBracket : s.toCharArray()) {
            if (isOpeningBracket(currBracket)) {
                openingBrackets.push(currBracket);
                continue;
            }

            if (openingBrackets.isEmpty()) {
                return false;
            }

            char lastOpeningBracket = openingBrackets.pop();
            if (neededBracket.get(currBracket) != lastOpeningBracket) {
                return false;
            }
        }

        return openingBrackets.isEmpty();
    }
    private boolean isOpeningBracket(char c) {
        return (c == '(' || c == '{' || c == '[');
    }
}
