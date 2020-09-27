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


file2="Maple wins. Remaining HP: 30.
Kakarot wins. Remaining HP: 280.
Sally wins. Remaining HP: 5.
Kakarot wins. Remaining HP: 270.
Kakarot wins. Remaining HP: 290.
Kakarot wins. Remaining HP: 300."

if cmp -s "HELLO" "HELLO"; then
    printf "HELLO"
else
    printf "NEM"
fi
