class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encodedString;
        
        for (std::string_view s : strs) {
            int stringSize = s.size();
            encodedString += std::to_string(stringSize);
            encodedString += "#";
            encodedString += s;
        }

	    return encodedString;
    }

    vector<string> decode(string s) {
        std::vector<std::string> decodedStrings;
	
	    for (int i = 0; i < s.size(); i++) {
            char currentChar = s[i];
            std::string stringLength = "";
            while (currentChar != '#') {
                stringLength += currentChar;
                i++;
                if (i > s.size()) {
				    break; 
			    }
                currentChar = s[i];
            }
            i += 1; // for #
            if (stringLength.empty()) {
                decodedStrings.push_back("");
                continue;
            }
            int stringLengthInt = std::stoi(stringLength);
            std::string toAdd = "";
            for (int j = i; j < i + stringLengthInt; j++) {
                toAdd += s[j];
            }
            decodedStrings.push_back(toAdd);
            i += stringLengthInt - 1;
            
        }
        return decodedStrings;
    }
};
