all: matrix

matrix: build-dir
	g++ -Wall -pedantic -std=c++11 -o build/matrix src/*.cpp -Isrc

build-dir:
	mkdir -p build

clean:
	rm -rf build
