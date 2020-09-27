#!/bin/bash

rm -f output.txt
touch output.txt

./a.out units/Maple.json units/Sally.json >> output.txt
./a.out units/Maple.json units/Kakarot.json >> output.txt
./a.out units/Sally.json units/Maple.json >> output.txt
./a.out units/Sally.json units/Kakarot.json >> output.txt
./a.out units/Kakarot.json units/Maple.json >> output.txt
./a.out units/Kakarot.json units/Sally.json >> output.txt

diff output.txt super_good_output.txt

if [ $? -eq 0 ]
then
echo "No differences. The test was OK!"
else
echo "Test failed."
fi

