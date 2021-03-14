#!/bin/bash
# ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
# ./a.out $ARG

MAX_ITER=100
TEST=1

echo '----------------------------------------'
echo  "All tests are done with " $MAX_ITER " iterations";
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
		echo "With 3 values"
		LIMIT=3
		FILE=problem_3
		NB=3
	elif [ "$TEST" -eq 2 ]; then
		echo "With 5 values"
		LIMIT=12
		FILE=problem_5
		NB=5
	elif [ "$TEST" -eq 3 ]; then
		echo "With 100 values"
		LIMIT=1500
		FILE=problem_100
		NB=100
	elif [ "$TEST" -eq 4 ]; then
		echo "With 500 values"
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

	echo "AVG:  $(($SUM / $ITERATIONS))"
	echo "MIN: " $MIN
	echo "MAX: " $MAX
	TEST=$((TEST+1))

done