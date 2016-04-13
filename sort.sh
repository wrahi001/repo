#!/bin/sh
array=(5 3 9 1 2 0)

for (( i=0; i < ${#array[@]}; i++)); 
do
	for (( j=i+1; j < ${#array[@]}; j++)); 
	do
		if (( ${array[i]} > ${array[j]} )); 
		then
			temp=${array[i]}
			temp2=${array[j]}
			array[i]=$temp2
			array[j]=$temp
		fi
	done

done

for a in "${array[@]}"
do
	echo $a
done

