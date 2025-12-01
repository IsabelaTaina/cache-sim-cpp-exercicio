CXX = g++
CXXFLAGS = -std=c++98 -Wall -O2 -Iinclude -Imy-lib/include

SRC = src/Cache.cpp \
      src/MemoriaPrincipal.cpp \
      src/Processador.cpp \
      src/main.cpp \
      my-lib/src/bitutils.cpp

OBJ = $(SRC:.cpp=.o)

OUTPUT = output/simulador.exe

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(OUTPUT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUTPUT)
