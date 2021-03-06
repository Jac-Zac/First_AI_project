#!/bin/bash

# this script start by compiling 
time make 

# then it run the algorithm and it let it train and save the weight 
echo $'\nRun the executable **************************************************\n'
./output
echo

# clean the rest
echo $'Clean but do not delete the saved weights *****************************\n'
make clean

# then change the value of TEST to true  
sed -i '' "s/TEST false/TEST true/" topology.h

# then make again 
echo $'\nMake for the second time ********************************************\n'
make 

# then ./output.out 
echo $'\nRun the executable **************************************************\n'
./output
echo

# then change TEST back to false 
sed -i '' "s/TEST true/TEST false/" topology.h

# and you can decide to clean everything
echo $'Cleaning everything **************************************************\n'
make clean

## Optional but useful for testing 
rm -f Saved_Weights
