#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h> 
class SafeFormatter{
public:
  SafeFormatter( const char * s ):fForm(s){}
  void compile(){fStream << fForm;}
  template< typename T, typename ... A >
    void compile(T v, A ... args){
      std::smatch sm;
      if( std::regex_search( fForm, sm, fRe )){
        fStream << sm.prefix().str() << sm[1].str();
        fStream << ( (sm[2]=="-") ? std::left : sm[3]=="" ? std::right : std::internal);
        if( sm[3]!="" )
          fStream << std::setfill(sm[3].str()[0]);
        if( sm[4]!="" ) fStream << std::setw( atoi(sm[4].str().c_str()) );
        if( sm[5]!="" ) fStream << std::setprecision( atoi(sm[5].str().c_str()) );
        if( sm[6]=="x") fStream << std::setbase(16);
        if( sm[6]=="o") fStream << std::setbase(8);
        fStream << v;
        fForm = sm.suffix().str();
        compile( args... ); 
      }else{
        //std::cout<<"ERROR"<<std::endl;
        // Pass Through
        fStream <<v;
        compile( args... ); 
      }
    }
  template< typename ... A >
    static std::string format(SafeFormatter form, A ... args){
      form.compile(args...);return form.str();
    }
  std::string str(){ return fStream.str(); }
private:
  std::string fForm;
  std::ostringstream fStream;
  const static std::regex fRe;
};
const std::regex SafeFormatter::fRe{R"(((?:^|[^%])(?:%%)*)%(-?)(0)?(\d+)?(?:\.(\d+))?([dfsxo]|ul))",std::regex::ECMAScript};