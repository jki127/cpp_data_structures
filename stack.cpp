#include<iostream>
#include<string>

using namespace std;

struct Node {
  string data;
  Node* next;
  Node(string s) : data(s){}
  Node(string s, Node* n) : data(s), next(n){}
};

class Stack{
  private:
    Node* _top;
  public:
    Stack(){}
    ~Stack(){
      while(_top) pop();
    }
    string top(){ return _top ? _top->data : nullptr; }
    void pop(){
      if(_top){
        Node* tmp = _top;
        _top = _top->next;
        delete tmp;
      }
    }

    void push(const string& s){
      Node* item = new Node(s, _top);
      _top = item;
    }
};

int main(){
  Stack letters;
  letters.push("a");
  letters.push("b");
  letters.push("c");
  cout << letters.top() << endl;
  letters.pop();
  cout << letters.top() << endl;
  letters.pop();
  cout << letters.top() << endl;
  letters.pop();

}
