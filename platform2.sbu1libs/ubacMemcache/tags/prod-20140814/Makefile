PKG_NAME=libubacmemcache
PKG_VERSION=1.2.2
PKG_DEPENDS=libmemcached-dev,libubacipc-1.2.4,libubacutils-1.2.2

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubacmemcache

CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2
SRC = src/*
BIN = bin
LIBS = -lmemcached -l:libubacipc.so.1.2.4 -l:libubacutils.so.1.2.2
INCLUDE = -I ./include/
OBJ = $(BIN)/$(OBJ_NAME)

all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)
#	strip $(OBJ)

install:
	test -d $(install_include_dir) ||  mkdir $(install_include_dir)
	cp include/* $(install_include_dir)/
	cp $(BIN)/* /usr/local/lib/
	ldconfig /usr/local/lib

clean:
	rm -f $(BIN)/*

