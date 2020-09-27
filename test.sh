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

if cmp -s $output.txt $good_output.txt
then
   echo "The files match"
else
   echo "The files are different"
fi

