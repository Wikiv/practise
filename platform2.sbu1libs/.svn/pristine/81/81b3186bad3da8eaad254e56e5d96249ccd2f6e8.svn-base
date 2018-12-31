PKG_NAME=libubacsbu2webapp
PKG_VERSION=1.4.9
UBAC_PKG_DEPENDS=libubacjsonparser-1.2.8,libubacsslinterface-1.2.6,libubachttpclient-1.4.5,libubacipc-1.4.1,libubacutils-1.2.5,libubaclogger-1.4.4,libubacyaml-1.2.1
DEB_PKG_DEPENDS=
DEB_18_04_PKG_DEPENDS=
RPM_PKG_DEPENDS=

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/sbu2webapp/

LIBS = -l:libubacjsonparser.so.1.2.8 -l:libubacsslinterface.so.1.2.6 -l:libubachttpclient.so.1.4.5 -l:libubacipc.so.1.4.1 -l:libubacutils.so.1.2.5 -l:libubaclogger.so.1.4.4 -l:libubacyaml.so.1.2.1

CPP = g++
CPPFLAGS =                             -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2                             
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
