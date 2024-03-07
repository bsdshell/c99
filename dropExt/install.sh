#!/bin/bash

#================================================================================ 
# Last Upate: Fri Oct  7 12:39:43 PDT 2016 
# Tue Nov 15 00:08:03 PST 2016  - add rsync, home dotfile to GoogleDrive/homedotfile
# 
# Script to manage all the small tasks such as editing and backup
#================================================================================ 
# all the colors in color.sh file
# [gf] open it 
# how to use in /Users/cat/myfile/script/jav.sh 
# e.g. printf "${FG_BR_RED}Hello World${RESET_ALL}\n"
# -------------------------------------------------------------------------------- 
# Tue May  7 16:46:25 2019 
# Add full path to ghc, Emacs can't find ghc from M-:
#================================================================================ 
# Sun Jul 28 18:21:09 2019 
# update to more generic file path
#================================================================================ 

# $(basename file.cpp) => file
# check number of arguments
#if [ "$#" -eq 0 ]; then
#else
#fi
# check last return code
#if [ "$?" -eq 0 ]; then
#else
#fi

#for var in $(ls) 
#do
#    $echo $var
#done 

function help(){
    printc 196 "help message"
}

source $HOME/myfile/bitbucket/script/AronLib.sh  
getpwd

MySymbin="$HOME/myfile/symbin"
MyBin="$HOME/myfile/mybin"
HaskellLib="$HOME/myfile/bitbucket/haskelllib"
hweb="$HOME/myfile/bitbucket/haskell_webapp"

hcmd="/usr/local/bin/ghc -i$HOME/myfile/bitbucket/haskelllib $1 -o "$(basename $1)
ghcProfile="/usr/local/bin/ghc -i$HOME/myfile/bitbucket/haskelllib -prof -fprof-auto -rtsopts $1" 

includeBoostFileSystem="/usr/local/Cellar/boost/1.72.0_2/include"
# boostSystem="/usr/local/Cellar/boost/1.72.0_2"
g++ -v

fl

outName="$ff/runbin/dropExt"
# run="g++ -I$clib  -I$includeBoostFileSystem -std=c++14 -O3 -Wall -pedantic line.cpp -lboost_filesystem -lboost_system -o $outName"
# run="g++ -I$clib  -I$boostinclude -std=c++14 -O3 -Wall -pedantic line.cpp -lboost_filesystem -lboost_system -o $outName"
# run="g++ -I$clib  -I$boostinclude -std=c++14 -O3 -Wall -pedantic f.cpp  -L$boostinclude/stage/lib  -lboost_system -lboost_filesystem -o $outName"

printc 200 "$run"
eval "$run"

ls -lah "$ff/runbin" | grep dropExt 

run="gcc -I$clib -O3 -Wall -pedantic dropExt.c -o $outName -lm"
echo "$run"
eval "$run"
