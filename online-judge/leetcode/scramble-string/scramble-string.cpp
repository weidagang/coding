#include<cstdio>
#include<string>
#include<vector>

class Solution {
public:
    bool isScramble(std::string s1, std::string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        if (0 == s1.size()) {
            return true;
        }

        const int len = s1.size();
        
        std::vector<bool> bits(len * len * len);
        
        for (int s = 1; s <= len; ++s) {
            for (int i = 0; i + s <= len; ++i) {
                for (int j = 0; j + s <= len; ++j) {
                    if (1 == s) {
                        bits[i * len * len + j * len + (s - 1)] = (s1[i] == s2[j]);
                    }
                    else {
                        for (int m = 1; m < s; ++m) {
                            if (bits[i * len * len + (j + s - m) * len + (m - 1)] && bits[(i + m) * len * len + j * len + (s - m - 1)]) {
                                bits[i * len * len + j * len + (s - 1)] = 1;
                                break;
                            }

                            if (bits[i * len * len + j * len + (m - 1)] && bits[(i + m) * len * len + (j + m) * len + (s - m - 1)]) {
                                bits[i * len * len + j * len + (s - 1)] = 1;
                                break;
                            }
                        }
                    }

                    //printf("bits[%d][%d][%d]=%d\n", i, j, s - 1, (int)bits[i * len * len + j * len + (s - 1)]);
                }
            }
        }

        return bits[0 * len * len + 0 * len + (len - 1)];
    }
};

int main() {
    Solution s;

    {
        bool yes = false;
        const char *s1 = "g";
        const char *s2 = "g";

        yes = s.isScramble(s1, s2);
        printf("%s %s %d\n\n", s1, s2, yes);
    }

    {
        bool yes = false;
        const char *s1 = "gr";
        const char *s2 = "rg";

        yes = s.isScramble(s1, s2);
        printf("%s %s %d\n\n", s1, s2, yes);
    }

    {
        bool yes = false;
        const char *s1 = "eat";
        const char *s2 = "tae";

        yes = s.isScramble(s1, s2);
        printf("%s %s %d\n\n", s1, s2, yes);
    }

    {
        bool yes = false;
        const char *s1 = "great";
        const char *s2 = "rgtae";

        yes = s.isScramble(s1, s2);
        printf("%s %s %d\n\n", s1, s2, yes);
    }

    {
        bool yes = false;
        const char *s1 = "abcd";
        const char *s2 = "bdac";

        yes = s.isScramble(s1, s2);
        printf("%s %s %d\n\n", s1, s2, yes);
    }

    return 0;
}
