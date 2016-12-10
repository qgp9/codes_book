#!/bin/bash

tmpdate=/tmp/$USER/rsync-backup/$(perl -e"printf qq/%d%02d%02d-%02d%02d%02d-%04d\n/,(localtime)[5..0],rand(10000)");echo "Backup to $tmpdate";rsync -b --backup-dir=$tmpdate $*
