#!/bin/bash

FILE=output.txt

if test -f $FILE
then
	rm $FILE
fi

for i in units/* 
do
	for j in units/*
	do
		if [ $i != $j ]
		then
			./a.out $i $j >> $FILE
		fi
	done
done

# Equality Comparison
if [ "$FILE" == "$good_otput.txt" ]; then
    echo "Strings match"
else
    echo "Strings don't match"
fi


