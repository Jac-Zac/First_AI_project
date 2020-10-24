#!/bin/bash

# this script start by compiling 
time make 
echo "Make time *************************************************"
echo ""

# then it run the algorithm and it let it train and save the weight 
time ./outupt.out

# clean the rest 
make clean_all
echo "Clean all *************************************************"
echo ""
echo ""

# then change the value of TEST to true  
sed -i '' "s/TEST false/TEST true/" topology.hpp 

# then make again 
make 
echo "Make for the second time *************************************************"
echo ""

# then ./output.out 
time ./outupt.out
echo "Run the executable and time it *************************************************"
echo ""

# then change TEST back to false 
sed -i '' "s/TEST true/TEST false/" topology.hpp

# and you can decide to clean everything
echo ""
echo "Cleaning everything *************************************************"
echo ""
make clean_all_weights
