CC=gcc
CFLAGS=-I. -g
CPPFLAGS = -I. -g -std=c++11
DEPS = ultron.h
OBJ = ultron.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	g++ -c -o $@ $< $(CPPFLAGS)

default: $(OBJ)
	$(CC) -o ultron $^ $(CFLAGS)

clean:
	rm -f *.o *.out

run: default
	./ultron

test-build: ultron.o test_main.o
	g++ -o ultron_test $^ $(CPPFLAGS) -lgtest -lgtest_main -lpthread

test: test-build
	./ultron_test

test-create: test-build
	./ultron_test --gtest_filter=Ultron.Creating

test-loading: test-build
	./ultron_test --gtest_filter=Ultron.Loading

test-adding: test-build
	./ultron_test --gtest_filter=Ultron.Adding

test-subtracting: test-build
	./ultron_test --gtest_filter=Ultron.Subtracting

test-branching: test-build
	./ultron_test --gtest_filter=Ultron.Branching

test-looping: test-build
	./ultron_test --gtest_filter=Ultron.Looping

test-counting-program: test-build
	./ultron_test --gtest_filter=Ultron.CountingProgram

test-count-u: default
	./ultron -f count.u
