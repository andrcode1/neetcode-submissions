class Solution {
public:

    bool isOpeningBracket(char c) {
	return (c == '(' or c == '[' or c == '{');
    }

    bool isClosingBracket(char c) {
        return (c == ')' or c == ']' or c == '}');
    }


    bool isValid(string s) {
        std::stack<char> brackets;
	    std::unordered_map<char, char> bracketMappings =
        {{')', '('},
         {']', '['},
         {'}', '{'}};
	    for (const char& bracket : s) {
            if (isOpeningBracket(bracket)) {
                brackets.push(bracket);
                continue;
            }
            if (isClosingBracket(bracket)) {
                if (brackets.empty()) {
				    return false;
			    }

                if (bracketMappings[bracket] == brackets.top()) {
                    brackets.pop();
                    continue;
                }
                return false;
            }
	}

	if (!brackets.empty()) {
		return false;
	}
	return true;

    }
};
