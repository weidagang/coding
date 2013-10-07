#include<algorithm>
#include<iostream>
#include<iterator>
#include<vector>

int main() {
    int nums[] = { 1, 3, 2, 4, 5, 1, 3, 5 };
    std::vector<int> vec(nums, nums + sizeof(nums) / sizeof(nums[0]));
    std::sort(vec.begin(), vec.end());
   
    do {
        // output
        std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        int i, j, k;

        // from right to left, find the first element vec[i] which can be bigger by swapping with a element at the right side
        for (i = vec.size() - 2; i >= 0; --i) {
            if (vec[i] < vec[i+1]) {
                break; 
            }
        }
     
        if (i < 0) {
            break;
        }
        
        // find the smallest element vec[k] which is larger than vec[i]
        k = -1;
        for (j = vec.size() - 1; j >= i + 1; --j) {
            if (vec[j] > vec[i] && (-1 == k || vec[j] < vec[k])) {
                k = j;
            }
        }
        
        // swap vec[i] and vec[k]
        std::swap(vec[i], vec[k]);

        // reverse the vec[i+1]..vec[n-1]
        std::reverse(vec.begin() + i + 1, vec.end());

    }
    while (true);

    return 0;
}
