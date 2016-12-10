#!/bin/bash
x=$1;
time {
TMPDIR=$(mktemp -d);
if [[  -z "$TMPDIR" || ! -d "$TMPDIR" ]];then exit 1;fi
avconv -i "$x" 2>&1 | perl -nle'/Duration:\s+(\d+):(\d+):(\d+)/ and $s=$1*3600+$2*60+$3}{for($i=60;$i<$s;$i+=int(($s-60)/20)){print $i}' | while read t;do
avconv -y -ss $t -i "$x" -f mjpeg -vframes 1 -s 320x240 $TMPDIR/tmp`printf "%06d" $t`.jpg;
done && montage $TMPDIR/tmp*.jpg -tile 5x -geometry +2+2 "$x".thumb1.jpg;# && rm $TMPDIR/tmp*.jpg
} 2>makethum.log