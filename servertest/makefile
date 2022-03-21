CC = g++
CFLAGS = -I/usr/local/include -L/usr/local/lib -g
OBJECTS =
LIBRARIES = -lhttpserver

all: minimal_https

minimal_https: 
	$(CC) $(CFLAGS) -o minimal_https minimal_https.cpp $(LIBRARIES)

clean:
	rm -f *.o