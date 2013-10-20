#include<cstdio>
#include<string>
#include<deque>
#include<vector>

class Solution {
private:
    struct Record {
        bool isLeft;
        int nLeft;
        int nRight;

        Record(bool i, int l, int r) : isLeft(i), nLeft(l), nRight(r) {
        }
    };

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;

        if (0 == n) {
            return result;
        }

        std::deque<Record> q;
        q.push_back(Record(true, 1, 0));

        while (!q.empty()) {
            Record top = q.back();
            //printf("isLeft=%d, nLeft=%d, nRight=%d\n", top.isLeft, top.nLeft, top.nRight);

            if (top.nLeft < n) {
                q.push_back(Record(true, top.nLeft + 1, top.nRight));
                continue;
            }
            
            if (top.nRight < top.nLeft) {
                q.push_back(Record(false, top.nLeft, top.nRight + 1));
                continue;
            }

            if (top.nLeft == n && top.nRight == n) {
                // save result
                std::string str;
                for (int i = 0; i < q.size(); ++i) {
                    str.append(q[i].isLeft ? "(" : ")");
                }
                //printf("%s\n", str.c_str());
                result.push_back(str);
                
                // find the first ( from the right to left that can be changed to )
                do {
                    q.pop_back();

                    if (!q.empty() && q.back().isLeft && q.back().nLeft - q.back().nRight > 1) {
                        q.pop_back();
                        q.push_back(Record(false, q.back().nLeft, q.back().nRight + 1));
                        break;
                    }
                }
                while(!q.empty());
            }
        }
    }
};

int main() {
    Solution s;

    for (int n = 0; n <= 3; ++n) {
        printf("%d\n", n);
        std::vector<std::string> result = s.generateParenthesis(n);
        for (int i = 0; i < result.size(); ++i) {
            printf("%s\n", result[i].c_str());
        }
    }

    return 0;
}
