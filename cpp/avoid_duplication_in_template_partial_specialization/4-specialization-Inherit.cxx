#include<iostream>
using namespace std;

template<class T, int I>
class MyClassB;

// Base Template Class
template<class T, int I>
class MyClassB {
public:
  MyClassB(){}
  virtual void doSomething(){}
};


// Inherited Implementation
template<class T, int I>
class MyClassBImpl : public MyClassB<T,I>{
public:
  MyClassBImpl():MyClassB<T,I>(){ 
    cout<<"Constructor of MyClassBImpl : default"<<endl; 
  }
  virtual void doSomething(){
    cout<<"doSomething in MyClassBImpl : default"<<endl;
  }
};

template<class T>
class MyClassBImpl<T,1> : public MyClassB<T,1> {
public:
  MyClassBImpl():MyClassB<T,1>(){ 
    cout<<"Constructor of MyClassBImpl : I==1"<<endl; 
  }
  virtual void doSomething(){
    cout<<"doSomething in MyClassBImpl : I==1"<<endl;
  }
};

// TEST
int main(){
  MyClassBImpl<int, 1> a1; 
  MyClassBImpl<int, 2> a2; 
  MyClassBImpl<int, 3> a3;
  a1.doSomething();
  a2.doSomething();
  a3.doSomething();
}

