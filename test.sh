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
