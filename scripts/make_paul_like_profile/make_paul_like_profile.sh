#!/bin/bash

if [[ $# -lt 2 ]]; then 
  echo "usage: $0 <forground image> <background image> [output name]"
  exit 1;
fi


Img1=$1;
Img2=$2;
OutName=${3:-"temp_out.png"};

if [[ ! -f $Img1 ]];then
  echo "$Img1 is not exists!!";
  exit 1;
fi
if [[ ! -f $Img2 ]];then
  echo "$Img2 is not exists!!";
  exit 1;
fi

TmpDir=$(mktemp -d);
echo "Working Directory is $TmpDir";
if [[ -z "$TmpDir" || ! -d "$TmpDir" ]];then
  echo "Temp Directory $TmpDir is not exists!!";
  exit 1;
fi

TmpImg1=$TmpDir/${Img1}.png
TmpImg2=$TmpDir/${Img2}.png

# Fill Red out of a main image
convert $Img1 -fill red -fuzz 20% -draw 'color 10,10 floodfill' -draw 'rectangle 200,650 550,700' $TmpImg1;
# Make red  transparent
convert $TmpImg1 -fill none -fuzz 20% -draw 'color 10,10 floodfill' $TmpImg1
# Make Mask of a main image
convert $TmpImg1  -alpha extract $TmpImg1
# Blur Mask
convert $TmpImg1 -blur 0x2.5 $TmpImg1
# remove background with the mask
convert $Img1 $TmpImg1 -alpha Off -compose CopyOpacity -composite $TmpImg1
# Resize a background image
convert $Img2 -resize $(identify -format "%[fx:w]x%[fx:h]" $TmpImg1) $TmpImg2
# Composite 
composite $TmpImg1 $TmpImg2 $OutName

echo "Result is $OutName"
