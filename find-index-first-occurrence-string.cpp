class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = -1;

        for(int i = 0; i < haystack.size(); i++) {

            if(haystack[i] == needle[0]) {

                result = i;
                int count = 0;

                if(i + needle.size() <= haystack.size()) {

                    for(int j = 0; j < needle.size(); j++) {

                        if(haystack[i + j] == needle[j]) {
                            count++;
                        }
                    }

                    if(count == needle.size()) {
                        return result;
                    }
                }
            }
        }

        return -1;
    }
};
