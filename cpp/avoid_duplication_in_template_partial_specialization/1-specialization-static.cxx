#include<iostream>
using namespace std;

template<class T, int I>
class MyClassB;

// HELPER
template<class T, int I>
struct MyClassBImpl{
  // You may be able to get a pointer of MyClassBImpl as a parameter
  static void Impl(){ 
    cout<<"Constructor of MyClassBImpl : default"<<endl; 
  }
  static void doSomething(){
    cout<<"doSomething in MyClassBImpl : default"<<endl;
  }
};
template<class T>
struct MyClassBImpl<T,1> {
  static void Impl(){ 
    cout<<"Constructor of MyClassBImpl : I==1"<<endl; 
  }
  static void doSomething(){
    cout<<"doSomething in MyClassBImpl : I==1"<<endl;
  }
};

// TEMPLATE
template<class T, int I>
class MyClassB {
public:
  MyClassB(){ MyClassBImpl<T,I>::Impl(); }
  void doSomething(){ 
    MyClassBImpl<T,I>::doSomething();
  };
};

// TEST
int main(){
  MyClassB<int, 1> a1;
  MyClassB<int, 2> a2;
  MyClassB<int, 3> a3;
  a1.doSomething();
  a2.doSomething();
  a3.doSomething();
}

