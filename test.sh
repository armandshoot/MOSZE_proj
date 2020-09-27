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

file1=output.txt
file2=good_output.txt

if cmp -s "$file1" "$file2"; then
    printf 'The file "%s" is the same as "%s"\n' "$file1" "$file2"
else
    printf 'The file "%s" is different from "%s"\n' "$file1" "$file2"
fi
