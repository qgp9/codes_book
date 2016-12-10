#!/usr/bin/env perl
use strict;
use warnings;
my $v = shift || 29387422028002;
my $i=2;
my @o = ();
while($i<=$v){
    if($v%$i==0){
        push @o,$i;
        $v/=$i;
    }else{
        $i += $i>2 ? 2 : 1;
        $i=$v if $i*$i>$v;
    }
}
print join " x ",@o;
print "\n";
