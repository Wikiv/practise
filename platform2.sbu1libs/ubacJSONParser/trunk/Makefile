PKG_NAME=libubacjsonparser
PKG_VERSION=1.2.8
UBAC_PKG_DEPENDS=libubacutils-1.2.5
DEB_PKG_DEPENDS=libyajl-dev\ \(=\ 2.1.0-2\)
DEB_18_04_PKG_DEPENDS=libyajl-dev
RPM_PKG_DEPENDS=libyajl2-dev

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/jsonparser

LIBS = -lyajl -l:libubacutils.so.1.2.5

CPP = g++
CPPFLAGS =             -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2             
SRC = src/*
BIN = bin

INCLUDE = -I ./include/
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
