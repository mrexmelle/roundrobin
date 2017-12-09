
testroundrobin: main.o
	g++ main.o roundrobin.o -o roundrobin 

roundrobin.o: src/roundrobin.cpp
	g++ -c src/roundrobin.cpp -Isrc -o roundrobin.o

main.o: src/main.cpp roundrobin.o
	g++ -c src/main.cpp -Isrc -o main.o

clean:
	rm -rf *.o roundrobin
