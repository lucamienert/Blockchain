exec = blockchain.out
src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic -lssl -lcrypto -ljsoncpp

$(exec): $(obj)
	g++ $(obj) $(flags) -o $(exec)

%.o: %.cpp include/%.h
	g++ -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm src/*.o

lint:
	clang-tidy src/*.cpp src/include/*.h
