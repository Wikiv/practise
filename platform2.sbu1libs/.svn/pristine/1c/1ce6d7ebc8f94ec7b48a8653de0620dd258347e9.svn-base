PKG_NAME=libubacdata
PKG_VERSION=1.2.1
PKG_DEPENDS=libubacyaml-1.2.1,libubaclogger-1.2.2,libubacipc-1.2.4,libubacutils-1.2.2,libubacjsonparser-1.2.2

OBJ_NAME = $(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/ubacdata/

CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC -O2
SRC = src
BIN = bin
LIBS = -l:libubacyaml.so.1.2.1 -l:libubaclogger.so.1.2.2 -l:libubacipc.so.1.2.4 -l:libubacutils.so.1.2.2 -l:libubacjsonparser.so.1.2.2
INCLUDE = -I ./include/
OBJ = $(BIN)/$(OBJ_NAME)

OBJFILES := $(patsubst $(SRC)/%.cpp,$(BIN)/%.o,$(wildcard $(SRC)/*.cpp))

OBJ: $(OBJFILES)
	$(CPP) $(CPPFLAGS) $(OBJFILES) $(LIBS) -o $(OBJ)  
#	strip $(OBJ)


$(BIN)/%.o:$(SRC)/%.cpp include/*.h 
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INCLUDE)		

install:
	test -d $(install_include_dir) ||  mkdir $(install_include_dir)
	cp include/* $(install_include_dir)/
	cp $(OBJ) /usr/local/lib/
	ldconfig /usr/local/lib

clean:
	rm -f $(BIN)/*

