//simple Hash Table
#include <iostream>
#include <functional>
#include <list>
#include <vector>

template<class Key, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key> >
class HashTable {
private:
    const size_t SIZE;
    
    std::vector<std::list<Key> > table;
public:
    HashTable() : SIZE(1e6) {
        table = std::vector<std::list<Key> >(SIZE);
    }

    ~HashTable() {}

    void insert(Key& aV) {
        table[Hash()(aV) % SIZE].push_back(aV);
    }
    
    void erase(Key& aV) {
        size_t hash = Hash()(aV) % SIZE;
        auto it = table[hash].begin();
        
        for (; it != table[hash].end(); ++it) {
            Key a = *it;
            if (KeyEqual()(aV, *it)) {
                table[hash].erase(it);
                return;
            }
        }
    }

    bool contains(Key& aV) {
        for (Key& el : table[Hash()(aV) % SIZE]) {
            if (KeyEqual()(el, aV)) {
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
    HashTable<std::string> ht;
    
    char req;
    std::string val;

    while (true) {
        std::cin >> req;
        
        if (req == '#') {
            break;
        }
        
        std::cin >> val;

        if (req == '+') {
            ht.insert(val);
        } else if (req == '?'){
            std::cout << (ht.contains(val) ? "YES\n" : "NO\n");
        } else if (req == '-') {
            ht.erase(val);
        }
    }

    return 0;
}
