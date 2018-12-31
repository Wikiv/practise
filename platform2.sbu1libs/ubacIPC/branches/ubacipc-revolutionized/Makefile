PKG_NAME=libubacipc
PKG_VERSION=1.4.0
UBAC_PKG_DEPENDS=libubacutils-1.2.4,libubacsslinterface-1.2.5
DEB_PKG_DEPENDS=
RPM_PKG_DEPENDS=

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubacipc/

LIBS = -lpthread -lssl -l:libubacutils.so.1.2.4 -l:libubacsslinterface.so.1.2.5

CPP = g++
CPPFLAGS =   -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2 
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
