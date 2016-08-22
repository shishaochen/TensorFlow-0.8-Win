CC = g++
AR = ar crv

HEADERS = -I..
CXXFLAGS = -O2 -std=gnu++11

OBJECTS = eight_bit_int_gemm/eight_bit_int_gemm.o
TARGET = libgemmlowp.a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) -o $@ $(HEADERS) $(CXXFLAGS) -c $<