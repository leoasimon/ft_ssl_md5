#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

Make -C ../
cp ../ft_ssl .

if [ -z "$1" ]
then
	echo "Usage: sh test.sh [hash]"
else
	while read p; do
		echo "$WHITE"
		echo "$p"
		echo "$p" | openssl $1 > real.txt
		echo "$p" | ./ft_ssl $1 > mine.txt
		cat real.txt

		DIFF=$(diff real.txt mine.txt)
		if [ "$DIFF" != "" ] 
		then
			echo "$RED"
			echo $DIFF
			echo "KO"
		else
			echo "$GREEN"
			echo "OK"
		fi
	done < some_messages.txt
	# FILES=$1/*
	# for f in $FILES ; do
	# 	echo "$WHITE"
	# 	echo "$f"
	# 	cat "$f" > cat.txt
	# 	./ft_cat "$f" > ft_cat.txt
	# 	DIFF=$(diff cat.txt ft_cat.txt) 
	# 	if [ "$DIFF" != "" ] 
	# 	then
	# 		echo "$RED"
	# 		echo $DIFF
	# 		echo "KO"
	# 	else
	# 		echo "$GREEN"
	# 		echo "OK"
	# 	fi
	# done
fi
