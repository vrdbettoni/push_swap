#!/bin/bash

MAX_ITER=100
TEST=1

if [ "$1" = "for" ]; then
	i=1
	MAX=0
	SUM=0
	MIN=100000000
	ITERATIONS=0
	LIMIT=1000000
	FILE=limit_arg
	if [ "$3" = "limit" ]; then
		LIMIT=$4
	fi
	echo '----------------------------------------'
	echo  $MAX_ITER "iterations with" $2 "random values"
	while [ "$i" -le 100 ]
	do
		ARG=`ruby -e "puts (1..$2).to_a.shuffle.join(' ')"`
		if ./push_swap $ARG | ./checker $ARG | grep -q KO
		then
            ./push_swap $ARG | ./checker $ARG
			echo "Error!"
			echo $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$LIMIT" ]
			then
			echo $NUMBER >> $FILE
			echo $ARG >> $FILE
			echo " " >> $FILE
		fi
		if [ "$NUMBER" -lt "$MIN" ]
			then
			MIN=$NUMBER;
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		echo -ne ''$i'%\r'
		SUM=$((SUM+$NUMBER))
		ITERATIONS=$((ITERATIONS+1))
        i=$((i+1))
	done
	echo "MIN: " $MIN
	echo "AVG:  $(($SUM / $ITERATIONS))"
	echo "MAX: " $MAX
	echo '----------------------------------------'

else

echo '----------------------------------------'
echo  "All tests are done with" $MAX_ITER "iterations";
while [ "$TEST" -le 4 ]
do 
	i=1
	MAX=0
	MIN=100000000
	ITERATIONS=0
	LIMIT=0
	FILE=problem_5
	SUM=0
	echo '----------------------------------------'
	if [ "$TEST" -eq 1 ]; then
		echo "With 3 random values"
		LIMIT=3
		FILE=problem_3
		NB=3
	elif [ "$TEST" -eq 2 ]; then
		echo "With 5 random values"
		LIMIT=12
		FILE=problem_5
		NB=5
	elif [ "$TEST" -eq 3 ]; then
		echo "With 100 random values"
		LIMIT=1500
		FILE=problem_100
		NB=100
	elif [ "$TEST" -eq 4 ]; then
		echo "With 500 random values"
		LIMIT=11500
		FILE=problem_500
		NB=500
	fi

	while [ "$i" -le "$MAX_ITER" ];
	do

		ARG=`ruby -e "puts (1..$NB).to_a.shuffle.join(' ')"`
		if ./push_swap $ARG | ./checker $ARG | grep -q KO
		then
            ./push_swap $ARG | ./checker $ARG
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
		if [ "$NUMBER" -lt "$MIN" ]
			then
			MIN=$NUMBER;
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		echo -ne ''$i'%\r'
		SUM=$((SUM+$NUMBER))
		ITERATIONS=$((ITERATIONS+1))
        i=$((i+1))

	done

	echo "MIN: " $MIN
	echo "AVG:  $(($SUM / $ITERATIONS))"
	echo "MAX: " $MAX
	TEST=$((TEST+1))

done
fi