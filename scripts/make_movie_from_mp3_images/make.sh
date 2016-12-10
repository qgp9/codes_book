#!/bin/bash

# LibAV, GPAC must be installed 
# image file name must be "<mp3 filename>.png" 
# ex) project/101.mp3.png

inputFile=${1:-"input.txt"}

## Check input file
if [[ -f "$inputFile" ]];then
  echo "Start to run with $inputFile"
else
  echo "$inputFile does not exists"
  exit 1;
fi

## Read input file
FinalOut="out.mp4"; 
cat "$inputFile" | perl -ne'( /^\s*$/ or /^#/ ) or print' | while read x; do 
  mp3="$x"
  fig="$x.png"
  outA="$x.A.mp4"
  outB="$x.B.mp4"
  outC="$x.C.mp4"
  if [[ ! -f "$mp3" ]];then
    echo "$mp3 doesn't exits"; exit 1;
  fi
  if [[ ! -f "$fig" ]];then
    echo "$fig doesn't exits"; exit 1;
  fi

  test -f "$outB" || avconv -threads auto -loop 1 -y  -i "$fig"   -i "$mp3"  -c:a mp3 -b:a 384k  -c:v h264 -c:s hd720 -r 1 -shortest  "$outB"
  test -f "$outC" || avconv -threads auto -loop 1 -y  -i "$fig"   -t 2 -ar 48000 -ac 2 -f s16le -i /dev/zero -c:a mp3 -b:a 384k  -c:v h264 -c:s hd720 -r 1 -shortest  "$outC"
  MP4Box -cat "$outB" -cat "$outC" "$FinalOut"
done