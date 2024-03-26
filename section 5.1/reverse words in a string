class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            char ch = s[left];
            if (ch != ' ') {
                temp += ch;
            } else if (ch == ' ') {
                if (!temp.empty()) {
                    if (!ans.empty()) {
                        ans = temp + " " + ans;
                    } else {
                        ans = temp;
                    }
                    temp = "";
                }
            }
            left++;
        }

        // Check if there's a last word remaining in the temp string

        if (!temp.empty()) {
            if (!ans.empty()) {
                ans = temp + " " + ans;
            } else {
                ans = temp;
            }
        }
        return ans;
    }
};
