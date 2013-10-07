#include<algorithm>
#include<string>
#include<iostream>
#include<cstdio>
#include<cstring>

int main() {
    char word[256];
    while(scanf("%s", word)) {
        if (0 == strcmp("#", word)) {
            break;
        }

        int len = strlen(word);
        
        int i, j, k;
        for (i = len - 1; i >= 0; --i) {
            if (word[i] < word[i+1]) {
                break;
            }
        }

        if (i < 0) {
            std::cout << "No Successor" << std::endl;
            continue;
        }
        
        k = -1;
        for (j = len - 1; j >= i + 1; --j) {
            if (word[j] > word[i] && (-1 == k || word[j] < word[k])) {
                k = j;
            }
        }

        std::swap(word[i], word[k]);

        std::reverse(word + i + 1, word + len);

        std::cout << word << std::endl;
    }
    return 0;
}

