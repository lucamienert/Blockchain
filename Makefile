exec = blockchain.out
src = $(wildcard src/*.cpp src/server/*.cpp)
obj = $(src:.cpp=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic -lssl -lcrypto -ljsoncpp -Iinclude

$(exec): $(obj)
	g++ $(obj) $(flags) -o $(exec)

%.o: %.cpp include/%.h
	g++ -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm src/*.o

lint:
	clang-tidy src/*.cpp src/server/*.cpp include/*.h include/server/*.h
