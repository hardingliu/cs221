all: index

index: index.o ordered_array.o			
	g++ -o index -g index.o ordered_array.o

ordered_array.o: ordered_array.cc ordered_array.h
	g++ -Wall -c -g ordered_array.cc

index.o: index.cc ordered_array.h	
	g++ -Wall -c -g index.cc

clean: 
	rm *.o
	rm index
	rm -rf index.dSYM
