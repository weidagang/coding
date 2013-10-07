#include <algorithm>
#include <string>
#include <map>
#include <iostream>

class Trie
{
private:
    typedef std::map<char, Trie*> T_Map;

    static char TAIL;

    char m_value;
    std::map<char, Trie*> m_children;

public:
    Trie(char value) : m_value(value) {
        std::cout << "Trie(" << value << ")" << std::endl;
    }

    ~Trie() {
        std::cout << "~Trie()" << std::endl;

        for (T_Map::iterator it = m_children.begin(); it != m_children.end(); ++it) {
            if (NULL != it->second) {
                delete it->second;
            }
        }
    }

    void add(const std::string& word) {
        std::cout << "+add(" + word << ")" << std::endl;
        if (0 == word.size()) {
            m_children[TAIL] = new Trie(TAIL);
        } else {
            std::cout << 1 << std::endl;
            char c = word[0];
            std::cout << 2 << std::endl;

            T_Map::iterator it_child = m_children.find(c);

            if (m_children.end() == it_child) {
                std::cout << 3 << std::endl;
                m_children[c] == new Trie(c);
                std::cout << 4 << std::endl;
            }

            it_child = m_children.find(c);
            if (m_children.end() != it_child) {
                std::cout << 5 << std::endl;
                const std::string& subword = word.substr(1);
                m_children[c]->add(subword);
                std::cout << 6 << std::endl;
            }
        }
    }

    bool exist(const std::string& word) {
        if (0 == word.size()) {
            return m_value == TAIL;
        }

        if (m_children.end() != m_children.find(word[0])) {
            return m_children[word[0]]->exist(word.substr(1));
        }

        return false;
    }
};

char Trie::TAIL = 0;

int main()
{
    Trie trie(0);
    trie.add("pole");
    /*
    trie.add("peek");
    trie.add("poke");
    bool found = trie.exist("peek");
    std::cout << "found: " << found << std::endl;
    trie.exist("pole");
    std::cout << "found: " << found << std::endl;
    */

    return 0;
}
