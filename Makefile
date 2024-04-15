CC=g++
CFLAGS=-Iinclude -std=c++11 -Wall
LDFLAGS=
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:src/%.cpp=build/%.o)
EXECUTABLE=build/myproject

all: build $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

build/%.o: src/%.cpp
	@mkdir -p build 
	$(CC) $(CFLAGS) -c $< -o $@

build:
	@mkdir -p build

clean:
	rm -f build/*
	rm -f data/results.csv
	rm -f data/results_distances.csv
	rm -f data/results_times.csv

run: $(EXECUTABLE)
	./$(EXECUTABLE)
