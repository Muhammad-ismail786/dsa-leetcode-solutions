class Solution {
public:
    int reverseBits(int n) {
        string binaryStr = bitset<32>(n).to_string();

        reverse(binaryStr.begin(), binaryStr.end());

        unsigned int reversed_decimal = stoul(binaryStr, nullptr, 2);

        return static_cast<int>(reversed_decimal);
    }
};
