#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef unsigned int uint;
typedef long long ll;

struct Node{
  ll value;
  Node * next;
  Node(ll v) : value{v}, next{nullptr}{}
  Node(ll v, Node* p):value{v}, next{p}{}
};

class MyList{
  private:
    Node * head;
  public:
    MyList() : head(nullptr) {}
    ~MyList(){
      Node* n = head;
      while(n != nullptr){
        Node* tmp = n->next;
        delete n;
        n = tmp;
      }
      head = nullptr;
    }

    Node * begin(){return head;}

    void push_back(const ll &value){
      if(head == nullptr) head = new Node(value);
      else {
        Node * n = head;
        while(n->next != nullptr) n = n->next;
        n->next = new Node(value);
      }
    }

    void push_front(const ll& value){
      if(head == nullptr) head = new Node(value);
      else {
        Node* tmp = head;
        head = new Node(value, tmp);
      }
    }
    void pop_back(){
      if(head == nullptr) return;
      Node* tmp;
      Node* n = head;
      while(n->next != nullptr){
        tmp = n;
        n = n->next;
      }
      tmp->next = nullptr;
      delete n;
    }
    void pop_front(){
      if(head == nullptr) return;
      Node* tmp = head;
      head = head->next;
      delete tmp;
    }
    void insert_after(Node *p, const ll &i){
      if(p == nullptr) return;
      if(p->next == nullptr) p->next = new Node(i);
      else {
        Node* tmp = p->next;
        p->next = new Node(i, tmp);
      }
    }

    uint size(){
      if(head == nullptr) return 0;
      Node * n = head;
      uint counter = 0;
      while(n != nullptr){
        n = n->next;
        ++counter;
      }
      return counter;
    }
    bool empty(){
      return head == nullptr;
    };
    void print(){
      Node* n = head;
      while(n != nullptr){
        cout << n->value;
        cout << " -> ";
        n = n->next;
      }
      cout << "nullptr" << endl;
    }
};

int main(){
  MyList lst;
  lst.push_back(2);
  lst.push_back(3);
  lst.push_front(1);
  lst.pop_back();
  lst.pop_front();
  lst.print();
  cout << "size: " << lst.size() << endl;
  lst.push_back(3);
  lst.push_front(1);
  lst.print();
  cout << "size: " << lst.size() << endl;
  lst.push_front(0);
  lst.push_back(4);
  lst.print();
  cout << "size: " << lst.size() << endl;
  lst.pop_front();
  lst.pop_back();
  lst.print();
  cout << "size: " << lst.size() << endl;

  cout << endl << "insert 8 after every number" << endl;
  for(Node* n = lst.begin(); n != nullptr; n = n->next->next){
    lst.insert_after(n, 8);
  }
  lst.print();
  cout << endl;

  MyList l;
  for(ll i=3;i>0;--i) l.push_back(i);
  l.print();
  for(ll i=5;i>3;--i) l.push_front(i);
  l.print();
  Node *p =l.begin()->next;
  l.insert_after(p,10);
  l.print();
  cout << endl;

  MyList e1;
  e1.push_back(1);
  cout << "expected: 1" << endl;
  e1.print();
  e1.push_back(1);
  cout << "expected: 1 1" << endl;
  e1.print();
  cout << endl;

  MyList e2;
  e2.push_back(1);
  e2.pop_back();
  cout << "expected: nullptr" << endl;
  e2.print();
  e2.pop_back();
  cout << "expected: nullptr" << endl;
  e2.print();
  cout << endl;

  MyList e3;
  e3.push_front(1);
  cout << "expected: 1" << endl;
  e3.print();
  e3.push_front(1);
  cout << "expected: 1 1" << endl;
  e3.print();
  cout << endl;

  MyList e4;
  e4.push_back(1);
  e4.pop_front();
  cout << "expected: nullptr" << endl;
  e4.print();
  e4.pop_front();
  cout << "expected: nullptr" << endl;
  e4.print();
  cout << endl;

  MyList e5;
  // insert_after should not insert if passed nullptr
  e5.insert_after(e5.begin(), 10);
  cout << "expected: nullptr" << endl;
  e5.print();
  e5.push_back(1);
  e5.insert_after(e5.begin(), 10);
  cout << "expected: 1 10" << endl;
  e5.print();
  cout << endl;

  MyList e6;
  cout << "expected: 0" << endl;
  cout << e6.size() << endl;
  cout << endl;

  MyList e7;
  cout << "expected: empty" << endl;
  if(e7.empty()) cout << "empty" << endl;
  cout << "expected: not empty" << endl;
  e7.push_back(1);
  if(!e7.empty()) cout << "not empty" << endl;
}
