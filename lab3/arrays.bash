#!/bin/bash
# arrays.bash -- Some array stuff
#
# Kurt Schmidt
#	11/2019
# 
# GNU bash, version 4.4.20(1)-release (x86_64-pc-linux-gnu), on
# GNU/Linux 4.15.0-62-generic #69-Ubuntu SMP x86_64
# 
# EDITOR: tabstop=2, cols=120
# 

tab='   '  # 3 spaces


echo 'To create an "indexed" array (they can be sparse):'
echo "${tab}\$  declare -a arr"
declare -a arr
echo

echo 'We can initialise them:'
echo "${tab}\$  arr=( a b c d x y z )"
arr=( a b c d x y z )
echo

echo -e "Use \${#arr[@]} to see the # of elements: ${#arr[@]}\n"
echo -e "Use \${arr[@]} to see the elements: ${arr[@]}\n"
echo -e "Use \${!arr[@]} to see the keys: ${!arr[@]}\n"

echo 'Use declare (typeset) -p to see the items of the array with indices:'
echo "${tab}\$  declare -p a"
echo "${tab}$(declare -p arr)"
echo

echo "We can look at slices using \${arr[@]:start:len}"
echo "2nd element, and the two following: \${arr[@]:1:3} :  ${arr[@]:1:3}"
echo "First 3 elements: \${arr[@]:0:3} :  ${arr[@]:0:3}"
echo "End of array, starting at 5th element:  \${arr[@]:4} :  ${arr[@]:4}"
echo

echo 'The most convenient way to append onto an array is to,'
echo -e 'effectively, build a new array:\n'

echo "${tab}\$  arr=( a b c )"
arr=( a b c )
echo "${tab}\$  arr=( \${arr[@]} x )"
echo "${tab}${tab}OR"
echo "${tab}\$  arr+=( x )"
arr=( ${arr[@]} x )
echo "${tab}arr: ${arr[@]}"
echo "${tab}$(declare -p arr)"
echo

echo "${tab}\$  arr+=( y z )"
arr+=( y z )
echo "${tab}arr: ${arr[@]}"
echo "${tab}$(declare -p arr)"
echo

echo "Further, these arrays don't really behave like indexed arrays."
echo -e "For instance, removing an element from within the array really doesn't work:\n"

echo '$ unset -v arr[2]'
unset -v arr[2]
echo

echo -e "The array is: ${arr[@]}\n"

echo -e "Note, the indices aren't as we hoped:  $(typeset -p arr)\n"

echo -e "To fix up the indices, we really need to form a new array:"
echo "\$ arr=( \${arr[@]:0:2} \${arr[@]:3}"
echo -e "Better:  $(typeset -p arr)\n"

echo -e "\nAdd to the end:"
echo "\$ arr=( \${arr[@]} last )"
echo "Or \$ arr+=( last )"
arr=( ${arr[@]} last )
echo ${arr[@]}

echo -e "\nAdd to the beginning:"
echo "\$ arr=( first \${arr[@]} )"
arr=( first ${arr[@]} )
echo ${arr[@]}

echo -e "\nInsert at index i:"
echo "\$ i=5"
echo "\$ arr=( \${arr[@]:0:\$i} new_item \${arr[@]:\$i} )"
i=5
arr=( ${arr[@]:0:$i} new_item ${arr[@]:$i} )
echo ${arr[@]}

echo -e "\nTo remove the first item:"
echo "\$ arr=( \${arr[@]:1} )"
arr=( ${arr[@]:1} )
echo ${arr[@]}

echo -e "\nTo remove the last item:"
echo "\$ arr=( \${arr[@]:0:\$(( \${#arr[@]}-1 )) )"
arr=( ${arr[@]:0:$(( ${#arr[@]}-1 ))} )
echo ${arr[@]}

echo -e '\nUse -A to create an associative array:'
echo "\$  declare -A dict"
declare -A dict
echo

echo 'Associative arrays take strings as indices'
echo "dict[Kurt]=chocolate"
dict[Kurt]=chocolate

echo "Variables can be used as keys:"
echo 'p=Jaga'
echo 'dict[$p]=strawberry'
p=Jaga
dict[$p]=strawberry

echo "To see all the keys:"
echo 'echo ${!dict[@]}'
echo ${!dict[@]}

echo "Use the quoted @ form to iterate over the keys:"
echo 'for k in "${!dict[@]} ; do echo "$k : ${dict[$k]}" ; done'
for k in "${!dict[@]}" ; do echo "$k : ${dict[$k]}" ; done

#------		Sorting   --------------------
	# (See https://stackoverflow.com/questions/7442417/how-to-sort-an-array-in-bash )
arr=( osif  "c b" oaif 3ij )
sorted=( $(sort <<< "$arr[*]" ) )

