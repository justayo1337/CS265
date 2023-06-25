#!/bin/bash

# loop through all the files in the workign directory
ls -1a "$PWD" | while read file; do

# check if the listed file is a regular file 
	if [[ -f "$file" ]] ; then 
	#outputs the file name and the # of words and lines in the file	
		echo "$file" $(wc -l < "$file") $(wc -w < "$file")
	
	else 
		continue
	
	fi


done 
