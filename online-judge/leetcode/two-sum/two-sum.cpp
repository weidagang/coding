#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution {
    private:
        struct IndexValue {
            int index;
            int value;

            IndexValue(int i, int v) : index(i), value(v) {
            }

            bool operator < (const IndexValue& iv) const {
                return this->value < iv.value;
            }
        };

    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> result;
            vector<IndexValue> ivs;
            
            // construct indexed values 
            for (int i = 0; i < numbers.size(); ++i) {
                ivs.push_back(IndexValue(i, numbers[i]));
            }
            
            // sort indexed values 
            sort(ivs.begin(), ivs.end());
            std::cout << "After sort:" << std::endl;
            for (int i = 0; i < ivs.size(); ++i) {
                std::cout << "[i=" << ivs[i].index << ", v=" << ivs[i].value << "] ";
            }
            std::cout << std::endl;
            
            // iterate on the num1
            for (int i = 0; i < ivs.size() - 1; ++i) {
                const int num1 = ivs[i].value;
                const int num2 = target - ivs[i].value;

                // binary search for the num2
                vector<IndexValue>::iterator it = lower_bound(ivs.begin() + i + 1, ivs.end(), IndexValue(-1, num2));
                if (it < ivs.end() && num2 == it->value) {
                    int idx1 = ivs[i].index < it->index ? ivs[i].index : it->index; 
                    int idx2 = ivs[i].index > it->index ? ivs[i].index : it->index; 
                    result.push_back(idx1+1);
                    result.push_back(idx2+1);
                    break;
                }
            }

            return result;
        }
};

void test(int n, int nums[], int target) {
    std::cout << "Input: target=" << target << ", nums=[ ";
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] << " ";
        v.push_back(nums[i]);
    }
    std::cout << "]" << std::endl;

    Solution s;
    vector<int> r = s.twoSum(v, target);

    std::cout << "Output: ";
    if (2 == r.size()) {
        std::cout << r[0] << " " << r[1] << std::endl;
    }
    else {
        std::cout << "no answer" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    {
        int nums[] = { 2,7,11,15 };
        int target = 9;
        test(sizeof(nums) / sizeof(nums[0]), nums, target);
    }

    {
        int nums[] = { 7, 11, 2, 15 };
        int target = 9;
        test(sizeof(nums) / sizeof(nums[0]), nums, target);
    }

    {
        int nums[] = { 15, 11, 2, 7 };
        int target = 9;
        test(sizeof(nums) / sizeof(nums[0]), nums, target);
    }

    {
        int nums[] = { 0, 0 };
        int target = 0;
        test(sizeof(nums) / sizeof(nums[0]), nums, target);
    }

    {
        int nums[] = { 1, 2, 3, 4 };
        int target = 1;
        test(sizeof(nums) / sizeof(nums[0]), nums, target);
    }

    return 0;
}
