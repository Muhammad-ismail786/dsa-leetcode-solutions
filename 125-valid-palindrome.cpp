class Solution {
public:
    bool isPalindrome(string s) {
        string clean;

        for(int i = 0; i < s.size(); i++) {

            if(isalnum(s[i])) {

                char lower_case = tolower(s[i]);
                clean += lower_case;

            }
        }

        string reversed;
        reversed = clean;

        reverse(reversed.begin(), reversed.end());

        if(clean == reversed) {
            return true;
        }
        else {
            return false;
        }
    }
};
