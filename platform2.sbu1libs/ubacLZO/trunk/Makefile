PKG_NAME=libubaclzo
PKG_VERSION=1.2.2
UBAC_PKG_DEPENDS=
DEB_PKG_DEPENDS=liblzo2-dev
DEB_18_04_PKG_DEPENDS=liblzo2-dev
RPM_PKG_DEPENDS=lzo-devel

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubaclzo/

LIBS = -llzo2

CPP = g++
CPPFLAGS =   -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2  
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
