#include "SafeFormatter.h"
//#include "SafeFormatterRegexp.h"

template< typename ... A >
void test_format( const char * form, A ... args ){
  std::cout<<std::setw(20)<<form<<" --- ";
  std::cout<<SafeFormatter::format( form, args... );
  std::cout<<std::endl;
}

int main(){
  //std::cout<<SafeFormatter::format("%%d :%d\n%%%%d:%%d\t%f--%.3f123", 1, 4, 2.5, 12.1)<<std::endl;
  //
  test_format("%d",12, " this gives error or just printed");
  test_format("escape %%d %%%d %%%% %%%%%d",12,12);
  test_format("simple %d int",12);
  test_format("%10d",12);
  test_format("%-10d",12);
  test_format("%-010d",12);
  test_format("%010d",-12);

  test_format("%f", 3.141592);
  test_format("%20f", 3.141592);
  test_format("%-20f", 3.141592);
  test_format("%-20.3f", 3.141592);
  test_format("%20.10f", 3.141592);
  test_format("%-.10f", 3.141592);
  test_format("%-020.10f",-3.141592);
  test_format("%020.10f", -3.141592);

  test_format("%s","test string");
  test_format("%5s","test string");
  test_format("%50s","test string");
  test_format("%-50s","test string");
  test_format("%050s","test string");
  test_format("%-050s","test string");

  test_format("%x",14);
  test_format("%o",14);

  test_format("%d\n%10d\n%-10d\n%010d\n",12,12,12,-12);
}