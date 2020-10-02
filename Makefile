CXX=g++
CXXFLAGS=-O5 -g -DDEBUG -m64 -L /lib64 -Wall `pkg-config gtkmm-3.0 --cflags`
LDFLAGS=-DLCB -DLENGTHTYPE=Uint -pthread `pkg-config gtkmm-3.0 --libs`
EXEC=vampireGameproject
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $?

.PHONY: clean mrproprer

clean:
	rm -rf *.o

mrproprer: clean
	rm -rf $(EXEC)

