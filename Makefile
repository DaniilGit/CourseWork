.PHONY: clean
PATHBIN = bin/
PATHBUILD = build/
PATHSRC = src/
PATHBINTEST = bin_test/
PATHBBUILDTEST = build_test/
PATHTEST = test/
 
all: bin build $(PATHBIN)sorts

$(PATHBIN)sorts: $(PATHBUILD)sorts.o libsorts.so
	gcc $(PATHBUILD)sorts.o -L. -lsorts -o $(PATHBIN)sorts

libsorts.so: $(PATHBUILD)bubble.o $(PATHBUILD)quick.o $(PATHBUILD)generator.o $(PATHBUILD)time_sort.o
	gcc -shared $(PATHBUILD)bubble.o $(PATHBUILD)quick.o $(PATHBUILD)generator.o $(PATHBUILD)time_sort.o -o libsorts.so

$(PATHBUILD)bubble.o: $(PATHSRC)bubble.c
	gcc -Wall -fPIC -c $(PATHSRC)bubble.c -o $(PATHBUILD)bubble.o

$(PATHBUILD)quick.o: $(PATHSRC)quick.c
	gcc -Wall -fPIC -c $(PATHSRC)quick.c -o $(PATHBUILD)quick.o

$(PATHBUILD)generator.o: $(PATHSRC)generator.c
	gcc -Wall -fPIC -c $(PATHSRC)generator.c -o $(PATHBUILD)generator.o

$(PATHBUILD)time_sort.o: $(PATHSRC)time_sort.c
	gcc -Wall -fPIC -c $(PATHSRC)time_sort.c -o $(PATHBUILD)time_sort.o

$(PATHBUILD)sorts.o: $(PATHSRC)sorts.c
	gcc -Wall -c $(PATHSRC)sorts.c -o $(PATHBUILD)sorts.o

test: bin_test build_test $(PATHBINTEST)test

$(PATHBINTEST)test: $(PATHBBUILDTEST)bubble.o $(PATHBBUILDTEST)quick.o $(PATHBBUILDTEST)generator.o $(PATHBBUILDTEST)time_sort.o $(PATHBBUILDTEST)main.o $(PATHBBUILDTEST)test.o
	gcc -Wall $(PATHBBUILDTEST)bubble.o $(PATHBBUILDTEST)quick.o $(PATHBBUILDTEST)generator.o $(PATHBBUILDTEST)time_sort.o $(PATHBBUILDTEST)main.o $(PATHBBUILDTEST)test.o -o $(PATHBINTEST)test

$(PATHBBUILDTEST)bubble.o: $(PATHSRC)bubble.c
	gcc -Wall -I src -c $(PATHSRC)bubble.c -o $(PATHBBUILDTEST)bubble.o

$(PATHBBUILDTEST)quick.o: $(PATHSRC)quick.c
	gcc -Wall -I src -c $(PATHSRC)quick.c -o $(PATHBBUILDTEST)quick.o

$(PATHBBUILDTEST)generator.o: $(PATHSRC)generator.c
	gcc -Wall -I src -c $(PATHSRC)generator.c -o $(PATHBBUILDTEST)generator.o

$(PATHBBUILDTEST)time_sort.o: $(PATHSRC)time_sort.c
	gcc -Wall -I src -c $(PATHSRC)time_sort.c -o $(PATHBBUILDTEST)time_sort.o

$(PATHBBUILDTEST)test.o: $(PATHTEST)test.c
	gcc -Wall -I src -c $(PATHTEST)test.c -o $(PATHBBUILDTEST)test.o

$(PATHBBUILDTEST)main.o: $(PATHTEST)main.c
	gcc -Wall -I src -c $(PATHTEST)main.c -o $(PATHBBUILDTEST)main.o

clean:
	rm -f $(PATHBUILD)*.o

bin:
	mkdir bin

build:
	mkdir build

build_test:
	mkdir build_test

bin_test:
	mkdir bin_test
