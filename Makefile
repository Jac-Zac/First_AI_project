# The compiler to use for the compilation  
CXX = g++
# The c++ flags to use for compilation
CXXFLAGS = -c -Wall -Wextra -O3 -std=gnu++17
# Object files 
OBJECTS = main.o 
# Object file deletions rm -f *.o 
OBJDEL = rm -f *.o
# Executable file 
EXEC = outupt.out

all: output
output: $(OBJECTS) da_includere.h game.hpp AI.hpp Weights.hpp Layer.hpp Net.hpp topology.hpp
	$(CXX) $(OBJECTS) -o $(EXEC) -pthread  
	@echo "Linked everything together"
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
# Clean only the .o files 
clean:
	$(OBJDEL)
# Also delete the executable 
clean_all:
	$(OBJDEL) $(EXEC)
# Delete also the Saved_Weights of the network 
clean_all_weights:
	$(OBJDEL) $(EXEC) Saved_Weights
