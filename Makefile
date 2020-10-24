# The compiler to use for the compilation  
CXX=g++
# The c++ flags to use for compilation
CXXFLAGS=-c -Wall -Wextra -O3 -std=gnu++17
# Object files 
OBJS=main.o 
# Header files 
HDRS=*.hpp
# Executable file 
BIN=output

#  game.hpp AI.hpp Weights.hpp Layer.hpp Net.hpp topology.hpp

all: $(BIN)

$(BIN): $(OBJS) $(HDRS)
	$(CXX) $(OBJS) -o $(BIN) -pthread  
	@echo "Linked everything together"
# Clean only the .o files 
clean:
	$(RM) $(OBJS)
# Also delete the executable 
clean_all:
	$(RM) $(OBJS) $(BIN)
# Delete also the Saved_Weights of the network 
clean_all_weights:
	$(RM) $(OBJS) $(BIN) Saved_Weights

# NO need for this because of the implicit dependences 
# main.o: main.cpp
#	$(CXX) $(CXXFLAGS) main.cpp
