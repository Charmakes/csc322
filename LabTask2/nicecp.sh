#!/usr/bin/tcsh
if ($# > 2 || $# < 2) then
    echo "Error, please enter two arguement vectors, file to copy and new name"
    exit
endif
	echo "original file name is $1"
	echo "new name is $2"

	
if (-e $2) then
    echo "The new filename already exists, do you wish to overwrite? Y/N"
	set answer=$<
	    if ($answer == "Y" || $answer == "y"  ) then
		echo "overwrote $2, copied $1 to $2"
		cp $1 $2
		exit
	    else
		echo "will not overwrite $2, exiting..."
	      	exit

	   endif

 else
	echo "copied $1 to $2"
	touch $2
	cp $1 $2
	exit

 endif
