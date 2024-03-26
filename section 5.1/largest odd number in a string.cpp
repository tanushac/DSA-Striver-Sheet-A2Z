class Solution {
public:
    string largestOddNumber(string num) {
            int n = num.length() - 1;

    for (int i = n; i >= 0; i--) {
        int ch = num[i] - '0';
        if (ch % 2 == 1) {
            string result = num.substr(0, i + 1);  // Corrected the substr parameters
            return result;
        }
    }

    return "";  // If no odd digit found, return "0" as the largest odd number
    }
};
