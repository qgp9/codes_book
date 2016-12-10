#include<iostream>
using namespace std;

template<class T, int I>
class MyClassB;

// HELPER
template<class T, int I>
class MyClassBImpl{
public:
  MyClassBImpl( MyClassB<T,I> *m):fMother(m){ 
    cout<<"Constructor of MyClassBImpl : default"<<endl; 
  }
  void doSomething(){
    cout<<"doSomething in MyClassBImpl : default"<<endl;
  }
private:
  MyClassB<T,I> *fMother;
};
template<class T>
class MyClassBImpl<T,1> {
public:
  MyClassBImpl( MyClassB<T,1> *m):fMother(m){ 
    cout<<"Constructor of MyClassBImpl : I==1"<<endl; 
  }
  void doSomething(){
    cout<<"doSomething in MyClassBImpl : I==1"<<endl;
  }
private:
  MyClassB<T,1> *fMother;
};

// TEMPLATE
template<class T, int I>
class MyClassB {
public:
  MyClassB():fImpl(this){}
  void doSomething(){ 
    fImpl.doSomething();
  };
private:
  MyClassBImpl<T,I> fImpl; 
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

