#include <stdint.h>
#include <iostream>

template<int N> struct MustBeZeroInCompileTime {};
template<>      struct MustBeZeroInCompileTime<0> {enum{check};};

template<int N> struct UnitType{};
template<> struct UnitType<1>{ typedef uint8_t  type; };
template<> struct UnitType<2>{ typedef uint16_t type; };
template<> struct UnitType<4>{ typedef uint32_t type; };
template<> struct UnitType<8>{ typedef uint64_t type; };

template < int nByte, int unitByte >
struct DataRep {
  enum { kCheck = 0
    + MustBeZeroInCompileTime< (nByte<unitByte) >::check
    + MustBeZeroInCompileTime< (nByte%unitByte) >::check
    };

  typedef typename UnitType<unitByte>::type Unit;
  enum{ kNUnits = nByte/unitByte };

  void print(){ std::cout<<"WHOA~ "<<nByte<<"\t"<<unitByte<<"\t"<<kNUnits<<std::endl; }

  Unit fUnits[ kNUnits ];

};

int main(){
  // This will be compiled well
  DataRep<128,8> a; a.print();
  
  // This will make a compile error
  DataRep<128,9> b; b.print();
  return 0;
}

