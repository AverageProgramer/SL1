#!/bin/sh

echo " Enter File Name : "
	read filename

counter=1

while [ $counter -lt 100 ]
do

	echo "------MENU-------"
	echo "1.Create File"
	echo "2.View File"
	echo "3.Insert Record"
	echo "4.Delete Record"
	echo "5.Modify Record"
	echo "6.Exit"

	echo "Enter your choice : "
	read choice

	case "$choice" in
	1)	gedit "$filename"
		;;

	2)	echo "---------DATA--------"
		echo "\nRoll No. \tName \t\tDept"
		cat "$filename"
		;;

	3)    echo "Enter Roll No. : "
		read roll

		echo "Enter Name : "
		read name

		echo "Enter Dept : "
		read Dept

		echo "$roll \t$name \t\t$Dept" >> "$filename"	# >> for appending
		echo "Done !!!"
		;;

	4)	echo "Enter Roll No. to be deleted : "
		read roll_to_delete

		grep -v $roll_to_delete $filename > temp		# All files except that printed in temp
		rm $filename						# Delete original
		mv temp $filename						# Rename

		echo "Done !!!"
		;;

	5)    echo "Enter Roll No. to be updated : "		# MODIFY
		read roll_to_update

		echo "Enter New Details"				# NEW DETAILS
		echo "Enter Roll No. : "
		read roll

		echo "Enter Name : "
		read name

		echo "Enter Dept : "
		read Dept

		sed -i "/$roll_to_update */c $roll \t$name \t\t$Dept" $filename	# * for whole line
		echo "Done !!!"

		;;

	6)    exit;;

	esac
	counter=$((counter+1))

done
