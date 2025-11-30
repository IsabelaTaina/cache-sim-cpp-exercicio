CXX = g++
CXXFLAGS = -std=c++98 -Iinclude -Wall -O2

SRC = src/Cache.cpp \
      src/MemoriaPrincipal.cpp \
      src/Processador.cpp \
      src/main.cpp

OBJ = $(SRC:.cpp=.o)

OUTPUT = output/simulador.exe

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(OUTPUT)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(OUTPUT)
