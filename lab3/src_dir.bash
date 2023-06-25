#!/bin/bash
# src_dir.bash -- Idiom for getting a script's directory
#
# Kurt Schmidt
#	11/2019
# 
# GNU bash, version 4.4.20(1)-release (x86_64-pc-linux-gnu), on
# GNU/Linux 4.15.0-62-generic #69-Ubuntu SMP x86_64
# 
# EDITOR: tabstop=2, cols=120
#
# Demonstrates:  readlink realpath
# 

in='   '  # 3 spaces

echo
echo "${in}\$0 is: $0"
echo "${in}\$BASH_SOURCE is: $BASH_SOURCE"

echo -e "\nWe need to be careful, might be called w/a relative path, or absolute path."
echo -e "readlink will resolve these, and symlinks."

echo -e "\nIt's worse, we need to sanitize input.  E.g., directory/file names like \$\'\\n\'."

echo -e "\nBASH_SOURCE is an array.  This script should be in the first entry, so, \$BASH_SOURCE should suffice."
echo -e "Here is the array:"
for i in "${BASH_SOURCE[@]}" ; do
	echo -e "${in}$i"
done

targ="$BASH_SOURCE"

	## READLINK
echo -e "${in}readlink -f -- \$targ:   $(readlink -f -- "$targ")"
echo -e "${in}dirname -- readlink -f -- \$targ:   $(dirname -- "$(readlink -f -- "$targ")" )"

src="$(dirname -- "$(readlink -f -- "$targ")" )/"

echo -e "\nSo, this script is found in: '$src'\n"


	## REALPATH
echo -e "\nUsing realpath:"
src="$(realpath -- "$targ")"
echo -e "${in}realpath returns this:  $src\n"

	## CD/PWD game
echo -e "\nThis idiom pops up, too.  N.B., there might be a difference between \`pwd\` and \$PWD"
echo "${in}dir=\"\$( cd \"\$( dirname -- \"\${BASH_SOURCE[0]}\" )\" && printf \"%sx\" \"$PWD\")\""
echo "${in}dir=\${dir%x}"
dir="$( cd "$( dirname -- "${BASH_SOURCE[0]}" )" && printf "%sx" "$PWD")"
dir=${dir%x}

echo ""

