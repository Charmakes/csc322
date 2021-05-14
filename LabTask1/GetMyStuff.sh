#!/bin/csh
echo "Welcome friend, here is your stuff: " 
set UID = `id -u $LOGNAME`
set GID = `id -g $LOGNAME`
set groupz = ` groups $LOGNAME`
echo "here is your user ID: "
echo $UID
echo "here is your Primary group ID: "
echo $GID
echo "here are your groups: "
echo $groupz
set homehome = `echo $HOME`
set homebash = `echo $SHELL`
echo "absolute path of bash shell:"
echo $homebash
echo "absolute path of your home directory"
echo $homehome
echo "here is your PATH environment variable"
echo `echo $PATH`
