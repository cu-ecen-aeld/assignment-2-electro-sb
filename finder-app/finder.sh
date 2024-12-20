#!/bin/bash
if [ $# -lt 2 ] 
then
	echo there must be at least 2 arguments,  given $#
	exit 1
else
	filesdir=$1
	searchstr=$2
	cd $filrsdir
	if [ -d $filesdir ]
       	then
		X=$(find $filesdir -type f| wc -l)
		Y=$(grep -r  $searchstr $filesdir| wc -l) 
				
		echo "The number of files are $X and the number of matching lines are $Y"

		exit 0

	fi

fi

echo "specified folder does not exist"
exit 1
