## avoid_duplication_in_template_partial_specialization
* Ideas for effective template partial specialization

## multi_vector	multi_vector
* Ideas for multi-dimensional vector
```
MultiVector4<int, 2> l24;
  l24.resize( 2 );
  l24[0] << 1 <<  2 <<  3 ; 
  l24[1] << 10 <<  20 <<  30 ; 
  l24[0].push_back(4);
  for( unsigned int i=0; i<l24.size(); i++ ){
    for( unsigned int j=0; j<l24[i].size(); j++ )
      cout<< l24[i][j] <<", ";
    cout<<endl;
  }
```

## safe_formater_template
* safe formater with variadic template ( replace of printf, sprintf )
```
std::string str = SafeFormatter::format(%10d",12);
```

## check_template_parameter_in_compile.cxx
* How to check values of template parameters in compile time

## pythonic_range.cxx	pythonic_range.cxx
* range function/method like python
* ```for( auto i : range( 1,3 )    ) cout<< i <<", ";cout<<endl;```

## vector_minus_index.cxx
* An index -1 for a last element of a vector like python
* ```vec[-1]```
