import subprocess
import os
import sys

exe = './' + sys.argv[1]
output = sys.argv[2]

unitPairs = [['Maple.json', 'Sally.json'],
             ['Maple.json', 'Kakarot.json'],
             ['Sally.json', 'Maple.json'],
             ['Sally.json', 'Kakarot.json'],
             ['Kakarot.json', 'Maple.json'],
             ['Kakarot.json', 'Sally.json']]


with open(output, 'w') as output_f:
    for pair in unitPairs:
        args = [exe, pair[0], pair[1]]
        subprocess.call(args,
                        stdout=output_f, stderr=output_f)
