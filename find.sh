#!/bin/bash

ERR=0
I=-1
J=1
i=1
while [ $i -le 500 ]
do
    ARG=`ruby -e "puts ($I..$J).to_a.shuffle.join(' ')"`
	if ./push_swap $ARG | ./checker $ARG | grep -q KO
	then
        # ./push_swap $ARG | ./checker $ARG
	    # echo "Error!"
		# echo $ARG
        echo $I "to" $J
		ERR=1
	fi
    i=$((i+1))
    I=$((I-1))
    J=$((J+1))
done