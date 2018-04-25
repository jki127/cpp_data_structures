#include<iostream>
#include<list>
#include<string>

using namespace std;

struct Pair {
  Pair(string k, string v) : key(k), value(v){}
  string key;
  string value;
};

class HashTable {
  private:
    int size;
    list<Pair*>* slots;
    int hash_func(const string& key){
      int num = (int) key[0];
      return num % size;
    }
  public:
    HashTable(){
      size = 10;
      slots = new list<Pair*>[size];
    }
    ~HashTable(){
      // deallocate pairs
      // deallocate lists
      // deallocate slots
    }
    void insert(const string& key, const string& value){
      int index = hash_func(key);
      Pair* p = new Pair(key, value);
      slots[index].push_front(p);
    }
    string get(const string& key){
      int index = hash_func(key);
      for(Pair* current : slots[index]){
        if(current->key == key) return current->value;
      }
      return "";
    }
    string operator[](const string& key){
      return get(key);
    }
};

int main(){
  HashTable h;
  h.insert("monday", "1");
  cout << h["monday"] << endl;
}
