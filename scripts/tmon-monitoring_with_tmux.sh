#!/bin/bash
# monitoring with tmux
com=${1:-"htop"}
tname=mon
twin=mon
tnw=$tname:$twin

tmux has-session -t $tname
if [ $? != 0 ]
then
  tmux new-session   -s $tname -n $twin -d ssh -t a1 "$com"
  tmux split-window  -t $tnw.0 -h ssh -t v1 "$com"
  tmux split-window  -t $tnw.0 -v ssh -t v2 "$com"
  tmux split-window  -t $tnw.1 -v ssh -t vr "$com"
  tmux select-pane   -t $tnw.0
fi
tmux attach -t $tname
