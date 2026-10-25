class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::string binary = std::bitset<32>(n).to_string();
        int counter = 0;
        for (char c : binary) {
            if (c == '1') {
                counter++;
            }
        }
        return counter;
    }
};
