#include<iostream>

struct Node{
    std::string key;
    int value;
    Node *next;
    Node(std::string k, int val)
        : key{k}, value{val}, next{} {}
};

class HashTable{
private:
    static const int SIZE{7};
    Node *dataMap[SIZE];
public:
    void printTable();  
    int hash(std::string key);
    void set(std::string key, int value);
    int get(std::string);
    std::vector<std::string> keys();
};

void HashTable::printTable(){
    for (size_t i{}; i < SIZE; ++i){
        std::cout << i << " : ";
        Node *temp{dataMap[i]};
        while (temp){
            std::cout << " {" << temp->key << ", " << temp->value << "} " << "->";
            temp = temp->next;
        }
        std::cout << "/0" << std::endl;
    }
}

int HashTable::hash(std::string key){
    int hash{};
    // size_t length{key.length()};
    // for (size_t i{}; i < length; ++i){
    //     int asciiValue = (int)key[i];
    //     hash = (hash + asciiValue * 23) % SIZE;
    // }
    for (const auto &k : key){
        int asciiValue = (int)k;
        hash = (hash + asciiValue * 23) % SIZE;
    }
    return hash;
}

void HashTable::set(std::string key, int value){
    int index{hash(key)};
    Node *newNode{new Node(key, value)};
    if(!dataMap[index]) 
        dataMap[index] = newNode;
    else{
        Node *temp{dataMap[index]};
        while (temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int HashTable::get(std::string key){
    int index{hash(key)};
    Node *temp{dataMap[index]};
    while(temp){
        if(temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return 0;
}

std::vector<std::string> HashTable::keys(){
    std::vector<std::string> allKeys;
    for(size_t i{}; i < SIZE; ++i){
        Node *temp{dataMap[i]};
        while (temp){
            allKeys.emplace_back(temp->key);
            temp = temp->next;
        }
    }
    return allKeys;
}

int main()
{
    HashTable *myHashTable{new HashTable()};

    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);
    
    myHashTable->set("bolts", 200);
    myHashTable->set("screws", 140);
    
    myHashTable->printTable();

    std::cout << myHashTable->get("screws") << std::endl;
    std::cout << myHashTable->get("bolts") << std::endl;
    std::cout << myHashTable->get("glass") << std::endl;

    std::vector<std::string> myKeys{myHashTable->keys()};

    std::cout << "All keys:" << std::endl;
    for (const auto &k : myKeys){
        std::cout << k << std::endl;
    }
    

}















