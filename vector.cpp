#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef unsigned int uint;

class MyVector{
  private:
    uint sz = 0;
    uint cap = 0;
    int * data = nullptr;
  public:
    MyVector() : sz(0), cap(0), data(nullptr){}
    MyVector(uint n){
      if(n > 0) reserve(n);
      sz = n;
    }
    MyVector(int *p, uint n){
      if(n > 0){
        reserve(n);
        std::copy(p, p+n, data);
        sz = n;
      }
    }
    MyVector(const MyVector& other){
      if(other.sz > 0){
        reserve(other.sz);
        std::copy(other.data, other.data + other.sz, data);
        sz = other.sz;
      }
    }
    ~MyVector(){
      delete[] data;
    }
    void reserve(uint n){
      if(n < cap) return;
      if(n < 1) return;
      int* tmp = new int[n];
      if(data != nullptr){
        std::copy(data, data+sz, tmp);
        delete[] data;
      }
      data = tmp;
      cap = n;
    }
    void push_back(const int & val){
      if(cap == sz) reserve(sz + 1);
      data[sz] = val;
      ++sz;
    }
    MyVector& operator=(const MyVector & other){
      if(this != &other){
        if(cap < other.sz){
          int* tmp = new int[other.sz];
          if(other.data != nullptr){
            std::copy(other.data, other.data + other.sz, tmp);
          }
          if(data != nullptr) delete[] data;
          data = tmp;
          cap = other.sz;
        }
        else {
          if(other.data != nullptr) std::copy(other.data, other.data+sz, data);
        }
        sz = other.sz;
      }
      return *this;
    }
    int& operator[](uint i){
      return data[i];
    }
    uint size(){
      return sz;
    }
    uint capacity(){
      return cap;
    }
    void print(){
      auto print_each = [](int& num){ cout << num << " "; };
      std::for_each(data, data+sz, print_each);
      cout << endl;
    }
};

int main(){
  int a[3]={1,2,3};
  MyVector ma(a,3), mb;
  mb=ma;
  MyVector mc=mb;
  mb=mb;
  ma[0]=3;
  mb[1]=7;
  mb.push_back(10);
  mb.push_back(11);
  ma.print();
  mb.print();
  mc.print();

  cout << endl << "=======" << endl << endl;
  MyVector cp(ma);
  cp.print();
  cout << "cap: " << cp.capacity() << endl;
  cout << "sz: " << cp.size() << endl;

  cout << "push_back(8)" << endl;
  cp.push_back(8);
  cp.print();
  cout << "cap: " << cp.capacity() << endl;
  cout << "sz: " << cp.size() << endl;

  cout << "reserve(20)" << endl;
  cp.reserve(20);
  cp.print();
  cout << "cap: " << cp.capacity() << endl;
  cout << "sz: " << cp.size() << endl;

  cout << "first element: cp[0]" << endl;
  cout << cp[0] << endl << endl;

  cout << "default constructor" << endl;
  MyVector d;
  cout << "cap: " << d.capacity() << endl;
  cout << "sz: " << d.size() << endl << endl;

  cout << "MyVector i(25)" << endl;
  MyVector i(25);
  cout << "cap: " << i.capacity() << endl;
  cout << "sz: " << i.size() << endl << endl;

  cout << endl;
}
