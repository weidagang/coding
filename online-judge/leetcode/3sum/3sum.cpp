#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1024;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size() - 2 && nums[i] <= 0; ++i) {
            // remove duplicates
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            const int num1 = nums[i]; 
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                const int num2 = nums[j]; 
                const int num3 = nums[k]; 
                const int sum = num1 + num2 + num3;
                if (sum == 0) {
                    vector<int> r; 
                    r.push_back(num1);
                    r.push_back(num2);
                    r.push_back(num3);
                    result.push_back(r);
                    
                    do { ++j; } while (j < k && nums[j] == nums[j-1]);
                    do { --k; } while (j < k && nums[k] == nums[k+1]);
                }
                else if (sum < 0) {
                    ++j;
                }
                else {
                    --k;
                }
            }
        }

        return result;
    }
};

int main() {
    int n;
    while(scanf("%d", &n)) {
        int nums[N];

        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
        }

        Solution s;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            v.push_back(nums[i]);
        }
        vector<vector<int> > result = s.threeSum(v);
        if (result.size() > 0) {
            for (int i = 0; i < result.size(); ++i) {
                for (int j = 0; j < result[i].size(); ++j) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
        }
        else {
            printf("No answer\n");
        }
    }
    return 0;
}

