import subprocess
import os
import sys

exe = './' + sys.argv[1]
output = sys.argv[2]

unitPairs = [['units/Maple.json', 'units/Sally.json'],
             ['units/Maple.json', 'units/Kakarot.json'],
             ['units/Sally.json', 'units/Maple.json'],
             ['units/Sally.json', 'units/Kakarot.json'],
             ['units/Kakarot.json', 'units/Maple.json'],
             ['units/Kakarot.json', 'units/Sally.json']]


with open(output, 'w') as output_f:
    for pair in unitPairs:
        args = [exe, pair[0], pair[1]]
        subprocess.call(args,
                        stdout=output_f, stderr=output_f)
