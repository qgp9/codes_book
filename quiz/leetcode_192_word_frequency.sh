#!/bin/bash

# https://leetcode.com/problems/word-frequency/
#192. Word Frequency

cat words.txt | perl -anle'$h{$_}++ for @F}{ print "$_ $h{$_}" for sort { $h{$b} <=> $h{$a} } keys %h'
