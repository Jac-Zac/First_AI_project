# O3 serve per ottimizzare, la differenza è notevole
output.o: main.o da_includere.h game.hpp AI.hpp Weights.hpp Layer.hpp Net.hpp topology.hpp
	g++ main.o -o output -pthread  
main.o: main.cpp
	g++ -c -O3 -std=gnu++17 main.cpp
clean:
	rm -rf *.o output	
clean_weights:
	rm -rf *.o output Saved_Weights	
