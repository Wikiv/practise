PKG_NAME=libubaclogger
PKG_VERSION=1.4.4
UBAC_PKG_DEPENDS=libubacipc-1.4.1,libubacyaml-1.2.1,libubacutils-1.2.5,libubacsslinterface-1.2.6
DEB_PKG_DEPENDS=
DEB_18_04_PKG_DEPENDS=
RPM_PKG_DEPENDS=

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubaclogger/

LIBS = -l:libubacipc.so.1.4.1 -l:libubacyaml.so.1.2.1 -l:libubacutils.so.1.2.5 -l:libubacsslinterface.so.1.2.6

CPP = g++
CPPFLAGS =              -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2              
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
