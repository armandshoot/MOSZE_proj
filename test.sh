#!/bin/bash

rm -f output.txt

./a.out units/Maple.json units/Sally.json >> output.txt
./a.out units/Maple.json units/Kakarot.json >> output.txt
./a.out units/Sally.json units/Maple.json >> output.txt
./a.out units/Sally.json units/Kakarot.json >> output.txt
./a.out units/Kakarot.json units/Maple.json >> output.txt
./a.out units/Kakarot.json units/Sally.json >> output.txt

diff --strip-trailing-cr output.txt plswork.txt

if [ $? -eq 0 ]
then
echo "No differences. The test was OK!"
else
echo "Test failed."
fi

