#!/bin/bash

[[ 13 > 2 ]] && echo true
# Q2
if grep chocolate mySettings &>/dev/null ; then
		echo "All we have to decide is what to do with the chocolate that is given us..."

fi
#Q3
x=13
echo $(( x/5 ))

#Q4
(( 27%2 == 1 ))
echo $?
