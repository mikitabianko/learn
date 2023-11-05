//simple Hash Table
#include <iostream>
#include <functional>
#include <list>
#include <vector>

template<class Key, class Hash = std::hash<Key> >
class HashTable {
private:
    const size_t SIZE;
    
    std::vector<std::list<size_t> > table;
public:
    HashTable() : SIZE(1e6) {
        table = std::vector<std::list<size_t> >(SIZE);
    }

    ~HashTable() {}

    void insert(Key& aV) {
        size_t hash = Hash()(aV);
        if (!contains(aV)) {
            table[hash % SIZE].push_back(hash);
        }
    }

    bool contains(Key& aV) {
        size_t hash = Hash()(aV);
        for (size_t& el : table[hash % SIZE]) {
            if (el == hash) {
                return true;
            }
        }
        return false;
    }
};

struct CustomHashFunction {
    long long operator() (std::string& str) {
        long long h = 0, P = 31, Q = 10e9 + 7;

        for (int i = 0; i < str.length(); i++) {
            h = (h * P + str[i] - 'a' + 1) % Q;
        }

        return h;
    }
};

int main() {
    HashTable<std::string, CustomHashFunction> ht;
    
    char req;
    std::string val;

    while (true) {
        std::cin >> req;
        
        if (req == '#') {
            return 0;
        }
        
        std::cin >> val;

        if (req == '+') {
            ht.insert(val);
        } else if (req == '?'){
            std::cout << (ht.contains(val) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
