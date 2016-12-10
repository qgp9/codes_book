find . -type f -print0 | xargs -0 md5sum > md5list.txt
perl -ne '/^(\S+)\s+(.+)/ and push @{$h{$1}},$2}{@$v>1&&print join"\n\t",$k,@$v,"\n"while($k,$v)=each%h' md5list.txt