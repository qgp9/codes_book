#!/usr/bin/env node

var num = 5712925402340856;
if( process.argv.length > 2 ) {
  num=process.argv[2];
}
var loopStartNum = 2;
var condition = true;
var prime = [];

while(condition){
  if (num%loopStartNum == 0) {
    num = num/loopStartNum;
    prime.push(loopStartNum);
  } else {
    loopStartNum += loopStartNum>2 ? 2:1;
    if(num == loopStartNum || loopStartNum*loopStartNum > num){
      prime.push(num);
      condition = false;
    }
  }
}
console.log(num);
console.log(prime);
