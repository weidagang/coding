#include<map>
#include<string>
#include<iostream>
#include<cassert>

typedef std::map<int, std::string> Map;

int main() {
    Map m;
    Map::iterator it;

    // insert
    m[1] = "value1";
    m[2] = "value2";
    m.insert(Map::value_type(3, "value3"));

    // find
    it = m.find(10);
    assert(it == m.end());

    it = m.find(1);
    assert(it == m.begin());

    // iterate
    assert(m.size() == 3);
    for (it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
    std::cout << std::endl;

    // erase
    m.erase(m.begin());
    assert(m.size() == 2);
    for (it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " -> " << m[it->first] << std::endl;
    }
    std::cout << std::endl;

    // update
    m[it->first] = "new value";
    assert(m.size() == 2);
    for (it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " -> " << m[it->first] << std::endl;
    }

    return 0;
}
