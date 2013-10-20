#include<cstdio>
#include<cstring>
#include<vector>
#include<string>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        const int N1 = s1.size();
        const int N2 = s2.size();
        const int N3 = s3.size();

        if (N1 + N2 != N3) {
            return false;
        }

        std::vector<bool> masks((N1 + 1) * (N2 + 1));
        masks[0] = true;
         
        for (int n1 = 0; n1 <= N1 && n1 <= N3; ++n1) {
            for (int n2 = 0; n2 <= N2 && n2 <= N3 - n1; ++n2) {
                if (n1 > 0 && s1[n1 - 1] == s3[n1 + n2 - 1] && masks[(n1 - 1) * (N2 + 1) + n2]) {
                    masks[n1 * (N2 + 1) + n2] = true;
                }

                if (n2 > 0 && s2[n2 - 1] == s3[n1 + n2 - 1] && masks[n1 * (N2 + 1)  + n2 - 1]) {
                    masks[n1 * (N2 + 1) + n2] = true;
                }

                //printf("masks[%d][%d]=%d\n", n1, n2, (int)masks[n1 * (N2 + 1) + n2]);
            }
        }

        for (int n1 = 0; n1 <= N1 && n1 <= N3; ++n1) {
            int n2 = N3 - n1;
            if (n2 <= N2 && masks[n1 * (N2 + 1) + n2]) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution s;
    
    char s1[128];
    char s2[128];
    char s3[256];
    while (3 == scanf("%s %s %s", s1, s2, s3)) {
        if (0 == strcmp(s1, "-")) {
            s1[0] = '\0';
        }
        if (0 == strcmp(s2, "-")) {
            s2[0] = '\0';
        }
        if (0 == strcmp(s3, "-")) {
            s3[0] = '\0';
        }
        bool r = s.isInterleave(s1, s2, s3);
        printf("%d\n", r);
    }
}
