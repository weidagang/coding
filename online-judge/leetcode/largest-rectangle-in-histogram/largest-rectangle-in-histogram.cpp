#include<cstdio>
#include<list>
#include<vector>

using namespace std;

class Solution {
    private:
        struct Record {
            int start; 
            int index;
            int height;

            Record(int s, int i, int h) {
                this->start = s;
                this->index = i;
                this->height = h;
            }
        };

    public:
        int largestRectangleArea(vector<int> &height) {
            int maxArea = 0;

            // push a special block at the end
            height.push_back(0);
            
            // keep heights in ascending order
            std::list<Record> lst;
            
            // push a special block at the beginning
            lst.push_back(Record(-1, -1, -1));
            
            // record the left most boundary for the current block
            for (int i = 0; i < height.size(); ++i) {
                while (lst.back().height >= height[i]) {
                    int area = lst.back().height * (i - lst.back().start);
                    if (area > maxArea) {
                        maxArea = area;
                    }
                    lst.pop_back();
                }

                int start = lst.back().index + 1;
                
                lst.push_back(Record(start, i, height[i]));
            }

            return maxArea;
        }
};

int main() {
    Solution s;
    
    int n = 0;
    while (scanf("%d", &n)) {
        vector<int> height;

        for (int i = 0; i < n; ++i) {
            int h;
            scanf("%d", &h);
            height.push_back(h);
        }

        int maxArea = s.largestRectangleArea(height);

        printf("max area: %d\n", maxArea);
    }
}
