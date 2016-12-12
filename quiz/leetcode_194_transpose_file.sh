#!/bin/bash

# https://leetcode.com/problems/transpose-file/
# 194. Transpose File

cat file.txt | perl -anle'$L[$_].=" $F[$_]" for 0..$#F}{ s/^ // && print for @L'
