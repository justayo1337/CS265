#!/bin/bash
# random - Describes 2 methods for getting random numbers right in Bash
#
# Kurt Schmidt
#
# 04.2020
#
# GNU bash, version 4.4.20(1)-release (x86_64-pc-linux-gnu), on
# GNU/Linux 4.15.0-88-generic x86_64
#
# Editor:  tabstop=2, cols=120
#

indent='   '

low=${1:-1}
high=${2:-100}

(( range = high - low + 1 ))

echo -e "\nThere are several ways we can get random numbeers from within Bash:"
echo -e "${indent}1.  Using the \$RANDOM variable"
echo -e "${indent}2.  Reading the special file /dev/random"

	###  $RANDOM
echo -e "\n\$RANDOM yields an integer on [0, 32767] ( [0, 2^15-1] )"
echo -e "${indent}Documentation can be found in the Bash manpage."
echo -e "${indent}Assign into it to seed it"
echo ""

# RANDOM=13   # to get the same sequence each time

for i in {1..4} ; do
	printf "%s%11d\n" "${indent}${indent}" $(( RANDOM % range + low ))
done

	###  /dev/random
echo -e "\n/dev/random yields bytes, as requested"
echo -e "${indent}Documentation can be found in section IV of the mangpages, under random:"
echo -e "${indent}${indent}man -s4 random"
echo -e "${indent}Use od to get B bytes, as an integer:"
echo -e "${indent}${indent}od -An -NB -i /dev/random"
echo ""

printf "bytes |  max value\n"
printf "%5s | %10s\n" '-----' '----------'
for i in {1..4} ; do
	printf "%4d  | %10d\n" $i $(( 2**(i*8) - 1 ))
done

echo ""

for i in {1..5} ; do
	r=$(od -An -N2 -i /dev/random)
	printf "%s%12d\n" "${indent}${indent}" $(( r % range + low ))
done

