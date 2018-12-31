CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC
SRC = src/*
LIBS = -lyajl -lubacutils++
INCLUDE = -I ./include/
OBJ = ./bin/libjsonparser++.so
INCLUDE_INSTALL = /usr/local/include/jsonparser

all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)
	strip $(OBJ)

install:
	./install.sh

clean:
	rm -f $(OBJ)

