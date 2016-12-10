#!/bin/bash

TargetNumber=${1:-5712925402340856}

{
  echo "##### Target Number = $TargetNumber"
  echo
  echo -n "##### primeFactor.pl : perl ";perl -E'say $^V'
  time ./primeFactor.pl $TargetNumber
  echo
  echo -n "##### primeFactor.js : nodejs ";node --version
  time ./primeFactor.js $TargetNumber
  echo
  echo -n "##### primeFactor.cxx : clang-600.0.57 -O2"
  g++ -O2 primeFactor.cxx >& /dev/null
  time ./a.out $TargetNumber
} 2>&1 | tee result.txt  



