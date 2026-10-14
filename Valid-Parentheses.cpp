class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            // Opening brackets
            if(s[i] == '(') {
                st.push(s[i]);
            }

            if(s[i] == '{') {
                st.push(s[i]);
            }

            if(s[i] == '[') {
                st.push(s[i]);
            }

            // Closing )
            if(s[i] == ')') {

                if(st.empty()) {
                    return false;
                }

                if(st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }

            // Closing }
            if(s[i] == '}') {

                if(st.empty()) {
                    return false;
                }

                if(st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
            }

            // Closing ]
            if(s[i] == ']') {

                if(st.empty()) {
                    return false;
                }

                if(st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
