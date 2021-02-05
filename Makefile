###########################################################
################### Makefile Template #####################
###########################################################

# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -c -Wall -Wextra -O2 -std=gnu++2a 

# Files  Object Headers end Executable 
OBJS=main.o 
HDRS=*.hpp
BIN=output

################# Unless you now what you are doing do not modify this part ################## 

all: $(BIN)

$(BIN): $(OBJS) $(HDRS)
	$(CXX) $(OBJS) -o $(BIN) -pthread  
	@echo "Linked everything together"

# Clean everything but doesn't delete the Saved_Weights file 
.PHONY: clean
clean:
	$(RM) $(OBJS) $(BIN)

################## main compilation will work with implicit dependences ################## 
