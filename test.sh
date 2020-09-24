#!/bin/bash

IFS=$'\n'

rm $2

for i in `cat input.txt`; do 
    echo $i | xargs ./$1 >> $2
done 
