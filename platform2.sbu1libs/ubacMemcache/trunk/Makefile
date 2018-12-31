PKG_NAME=libubacmemcache
PKG_VERSION=1.3.9
UBAC_PKG_DEPENDS=libubacipc-1.4.1,libubacutils-1.2.5
DEB_PKG_DEPENDS=libmemcached-dev
DEB_18_04_PKG_DEPENDS=libmemcached-dev
RPM_PKG_DEPENDS=libmemcached-devel

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubacmemcache

LIBS = -lmemcached -l:libubacipc.so.1.4.1 -l:libubacutils.so.1.2.5

CPP = g++
CPPFLAGS =           -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2           
SRC = src/*
BIN = bin

INCLUDE =   -I ./include/
OBJ = $(BIN)/$(OBJ_NAME)

all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)

install-bin:
	cp $(OBJ) /usr/local/lib/
	ldconfig /usr/local/lib

install-dev:
	test -d $(install_include_dir) ||  mkdir $(install_include_dir)
	cp include/* $(install_include_dir)/

install: install-bin install-dev

clean:
	rm -f $(BIN)/*
