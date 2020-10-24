#!/bin/bash

# this script start by compiling 
time make 

# then it run the algorithm and it let it train and save the weight 
echo $'\nRun the executable and time it *************************************************\n'
time ./outupt.out
echo 

# clean the rest
echo $'Clean all *************************************************\n'
make clean_all

# then change the value of TEST to true  
sed -i '' "s/TEST false/TEST true/" topology.hpp 

# then make again 
echo $'\nMake for the second time *************************************************\n'
make 

# then ./output.out 
echo $'\nRun the executable and time it *************************************************\n'
time ./outupt.out
echo 

# then change TEST back to false 
sed -i '' "s/TEST true/TEST false/" topology.hpp

# and you can decide to clean everything
echo $'Cleaning everything *************************************************\n'
make clean_all_weights
