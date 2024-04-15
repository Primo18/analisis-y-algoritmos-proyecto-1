CC=g++
CFLAGS=-Iinclude -std=c++11 -Wall
LDFLAGS=
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:src/%.cpp=build/%.o)
EXECUTABLE=build/myproject

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*
	rm -f data/results.csv
	rm -f data/results_distances.csv
	rm -f data/results_times.csv

run: $(EXECUTABLE)
	./$(EXECUTABLE)
