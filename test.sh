#!/bin/bash
# ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
# ./a.out $ARG

MAX=0
ITERATIONS=0
LIMIT=12
FILE=problem_5
SUM=0
i=1
while [ "$i" -le 500 ];
do
		ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
		if ./push_swap $ARG | ./checker $ARG | grep -q KO
		then
            ./push_swap $ARG | ./checker/./a.out $ARG
			echo "Error!"
			echo $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$LIMIT" ]
			then
			echo $NUMBER >> $FILE
			echo $ARG >> $FILE
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		echo $i ":" $NUMBER
		SUM=$((SUM+$NUMBER))
		ITERATIONS=$((ITERATIONS+1))
        i=$((i+1))
done

echo "AVG: $(($SUM / $ITERATIONS))"
echo "MAX: " $MAX