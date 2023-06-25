
function fact {
	local n f
	n="$1"

	if (( n < 2 )) ; then
		echo 1
		return
	fi

	# echo $(( n * $( fact $(( n-1 )) ) ))   # This works, but, tough to look at

	f=$( fact $(( n-1 )) )
	echo $(( n * f ))

}

fact 6

