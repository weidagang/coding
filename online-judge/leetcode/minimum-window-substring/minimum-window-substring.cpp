#include<cstdio>
#include<memory.h>
#include<string>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int minFrom = -1;
        int minSize = -1;

        ::memset(mTCount, 0, sizeof(mTCount));
        ::memset(mSCount, 0, sizeof(mSCount));

        // the number of characters in T
        int nT = 0;

        // initialize the info of T
        for (int i = 0; i < T.size(); ++i) {
            mTCount[T[i]]++;
            nT++;
        }
        
        int from = 0; //_from begins from the left most 

        // fix the _from, try to find the left most _to so that S[from, to] covers all the chars in T
        for (int to = 0; to < S.size(); ++to) {
            {
                char t = S[to];

                // update the count of chars in S[from, to]
                mSCount[t]++;
                
                // update the count of chars in T covered by S 
                // !! TRICK: if a char only appears in T for n time(s), we must not decrease the nT more than it.
                if (mSCount[t] <= mTCount[t]) {
                    nT--;
                }
            }
            
            // all the chars in T are covered by S[from, to]
            if (0 == nT) {
                // fix the _to, try to find the right most _from but still preserving the coverage of T
                while (true) {
                    char f = S[from++];
                    
                    // update the count of chars in S[from, to]
                    mSCount[f]--;

                    // the coverage is broken
                    if (mSCount[f] < mTCount[f]) {
                        nT++;
                        
                        // record the current minimum window 
                        int size = to - (from - 1) + 1;
                        if (-1 == minSize || size < minSize) {
                            minFrom = from - 1;
                            minSize = size;
                        }

                        break;  
                    }
                }
            }
        }

        return minSize <= 0 ? "" : S.substr(minFrom, minSize);
    }

private:
    int mTCount[256]; // store the count of characters in T 
    int mSCount[256]; // record the count of characters in the range of S[from, to]
};

const int N = 1024;
char buffer1[N];
char buffer2[N];

int main() {
    Solution s;
    while (scanf("%s", buffer1)) {
        scanf("%s", buffer2);
        string minWin = s.minWindow(buffer1, buffer2);
        printf("%s\n", minWin.c_str());
    }
    return 0;
}
