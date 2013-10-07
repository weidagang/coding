#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <functional>

struct person {
    std::string m_name;
    int m_age;

    person(const std::string& name, const int& age) : m_name(name), m_age(age) {
    }

    bool operator<(const person& rhs) const {
        return this->m_name < rhs.m_name;
    }

    friend std::ostream& operator<<(std::ostream& os, const person& p);
};

std::ostream& operator<<(std::ostream& os, const person& p) {
    os << p.m_name << "(" << p.m_age << ")";
    return os;
}

template<typename T>
struct less_by_age_asc {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs.m_age < rhs.m_age;
    }
};

template<typename T>
struct less_by_age_desc {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs.m_age > rhs.m_age;
    }
};


int main() {
    std::vector<person> vec;
    vec.push_back(person("todd", 31));
    vec.push_back(person("april", 29));
    vec.push_back(person("monad", 1));

    // sort by member < operator
    std::cout << "sort by name asc:" << std::endl;
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<person>(std::cout, " "));
    std::cout << std::endl;
    
    // sort by less functor
    std::cout << "sort by age asc:" << std::endl;
    std::sort(vec.begin(), vec.end(), less_by_age_asc<person>());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<person>(std::cout, " "));
    std::cout << std::endl;

    // sort by less functor
    std::cout << "sort by age desc:" << std::endl;
    std::sort(vec.begin(), vec.end(), less_by_age_desc<person>());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<person>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
