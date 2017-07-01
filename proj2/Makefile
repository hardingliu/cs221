all: huftree
	
huftree: huftree.o codetree.o
	g++ -o huftree -g huftree.o codetree.o
	
codetree.o: codetree.cc codetree.h
	g++ -Wall -c -g codetree.cc
	
huftree.o: huftree.cc codetree.h
	g++ -Wall -c -g huftree.cc
	
clean:
	rm *.o
	rm huftree





