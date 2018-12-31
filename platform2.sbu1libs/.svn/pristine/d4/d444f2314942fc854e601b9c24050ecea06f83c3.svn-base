CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC
SRC = src/*
LIBS = -lsybdb -lubacipc++
INCLUDE = -I ./include/
OBJ = ./bin/libubacmssql++.so
INCLUDE_INSTALL = /usr/local/include/ubacmssql

all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)
	strip $(OBJ)

install:
	./install.sh

clean:
	rm -f $(OBJ)
