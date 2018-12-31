PKG_NAME=libubacwebservice
PKG_VERSION=1.2.2
PKG_DEPENDS=libubachttpclient-1.2.1,libubacdata-1.2.1,libubacutils-1.2.2,libubacipc-1.2.5,libubaclogger-1.2.2,libubacsslinterface-1.2.2,libubacyaml-1.2.1

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubacwebservice

CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2
SRC = src/*
BIN = bin
LIBS = -l:libubachttpclient.so.1.2.1 -l:libubacdata.so.1.2.1 -l:libubacsslinterface.so.1.2.2 -l:libubacutils.so.1.2.2 -l:libubacipc.so.1.2.5 -l:libubaclogger.so.1.2.2 -l:libubacyaml.so.1.2.1
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

