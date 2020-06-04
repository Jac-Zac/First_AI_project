# O3 serve per ottimizzare, la differenza è notevole
output.o: main.o da_includere.h game.h AI.h Weights.h Layer.h Net.h
	g++ main.o -o output -pthread  
main.o: main.cpp
	g++ -c -O3 -std=gnu++17 main.cpp
clean:
	rm -rf *.o output	
