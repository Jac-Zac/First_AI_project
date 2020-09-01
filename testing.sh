#!/bin/bash

# this script start by compiling 
time make 

# then it run the algorithm and it let it train and save the weight 
time ./output

# clean the rest 
make clean 

# then change the value of TEST to true  
sed -i '' "s/TEST false/TEST true/" da_includere.h

# then make again 
make 

# then ./output 
./output 

# then change TEST back to false 
sed -i '' "s/TEST true/TEST false/" da_includere.h

# and you can decide to clean everything 
