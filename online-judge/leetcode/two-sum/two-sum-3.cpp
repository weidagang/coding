#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> result;
            unordered_map<int, int> v2i;
            for (int i = 0; i < numbers.size(); ++i) {
                unordered_map<int, int>::iterator it = v2i.find(target - numbers[i]);
                if (v2i.end() != it) {
                    result.push_back(it->second + 1);
                    result.push_back(i + 1);
                    break;
                }
                else {
                    v2i[numbers[i]] = i;
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
