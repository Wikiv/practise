CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC
SRC = src/*
LIBS = -lmemcached -lubacipc++
INCLUDE = -I ./include/
OBJ = ./bin/libubacmemcache++.so
INCLUDE_INSTALL = /usr/local/include/ubacmemcache

all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)
	strip $(OBJ)

install:
	./install.sh

clean:
	rm -f $(OBJ)

