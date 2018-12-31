PKG_NAME=libubacmssql
PKG_VERSION=1.3.9
UBAC_PKG_DEPENDS=libubacipc-1.4.1
DEB_PKG_DEPENDS=freetds-dev
DEB_18_04_PKG_DEPENDS=freetds-dev
RPM_PKG_DEPENDS=freetds-devel

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubacmssql

LIBS = -lsybdb -l:libubacipc.so.1.4.1

CPP = g++
CPPFLAGS =             -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2             
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
