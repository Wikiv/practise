PKG_NAME=libubacta
PKG_VERSION=1.2.0
PKG_DEPENDS=libubacipc-1.2.0,libubacdata-1.2.0

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubacta/

CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC
SRC = src/*
BIN = bin
LIBS = -lta_lib -l:libubacipc.so.1.2.0 -l:libubacdata.so.1.2.0
INCLUDE = -I ./include/
OBJ = $(BIN)/$(OBJ_NAME)

all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)
	strip $(OBJ)

install:
	test -d $(install_include_dir) ||  mkdir $(install_include_dir)
	cp include/* $(install_include_dir)/
	cp $(BIN)/* /usr/local/lib/
	ldconfig /usr/local/lib

clean:
	rm -f $(BIN)/*

