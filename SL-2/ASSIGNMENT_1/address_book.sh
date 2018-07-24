#!/bin/sh

echo " Enter File Name : " 
	read filename

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
	
	echo "$roll \t$name \t\t$Dept" >> "$filename"
	echo "Done !!!"
	;;

4)	echo "Enter Roll No. to be deleted : "
	read roll_to_delete
	
	grep -v $roll_to_delete $filename > temp
	rm $filename
	mv temp $filename
	
	echo "Done !!!"
	;;

5)    echo "Enter Roll No. to be deleted : "
	read roll_to_update
	
	grep -v $roll_to_update $filename > temp
	rm $filename
	mv temp $filename
	
	
	echo "Enter New Details"
	echo "Enter Roll No. : "
	read roll
	
	echo "Enter Name : "
	read name
	
	echo "Enter Dept : "
	read Dept
	
	echo "$roll \t$name \t\t$Dept" >> "$filename"
	echo "Done !!!" 
	
	;;
	 
6)    exit;; 

esac
