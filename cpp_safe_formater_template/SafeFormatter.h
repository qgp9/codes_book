#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h> 
class SafeFormatter{
public:
  SafeFormatter( const char * s ):fForm(s),fIterator(fForm.begin()){}
  void compile(){return ;}
  template< typename T, typename ... A >
    void compile(T v, A ... args){
      auto &it = fIterator;
      auto end = fForm.end();

      for( ;it!=end;it++ ){
        if( *it != '%' ){
          fStream << *it;
        }else{
          bool escape = true;
          while( it!=end && *it=='%' ){ 
            escape=!escape;
            if( escape ) fStream << "%%";
            it++; 
          }
          if( !escape ){
            bool        _left = false;
            auto        _align = std::right;
            std::string _width;
            std::string _prec;
            std::string _fill;
            if( *it == '-' ) { _align=std::left; it++; }
            if( *it == '0' ) { _fill='0'; it++; }
            while(it!=end && *it=='0' ) it++;
            while(it!=end && *it>='0' && *it<='9'){ _width += *it; it++;}
            if( *it == '.' ){
              it++;
              while(it!=end && *it>='0' && *it<='9'){ _prec += *it; it++;}
            }
            int iwidth = atoi(_width.c_str());
            int iprec  = atoi(_prec.c_str());
            if( *it=='d' || *it=='f' || *it=='s' || *it=='x' || *it=='o' ){
              fStream << _align;
              if( iwidth>0 ) fStream << std::setw(iwidth);
              if( iprec>0  ) fStream << std::setprecision(iprec);
              if( _fill.length()>0 ) {
                if( _align == std::left ) fStream<<std::left;
                else fStream<<std::internal;
                fStream <<std::setfill(_fill[0]);
              }
              if( *it=='x' ) fStream<<std::setbase(16);
              if( *it=='o' ) fStream<<std::setbase(8);
              fStream << v;
              it++;
              compile(args...);
              return;
            }else{
              std::cout<<"ERROR"<<std::endl;
              return;
            }
          }
        }
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
  std::string::iterator fIterator;
};