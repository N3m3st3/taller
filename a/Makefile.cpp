# Compilador y opciones de compilación
CC := g++
CFLAGS := -std=c++11 -Wall -Wextra -O2

# Directorios de inclusión
INCLUDES :=

# Bibliotecas adicionales
LIBS := -lm -fopenmp

# Archivos fuente y objeto
SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)

# Nombre del ejecutable
TARGET := myprogram

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

