CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC
SRC = src/*
LIBS = -lubacipc++ -lubacyaml++
INCLUDE = -I ./include/ -I /usr/include/libxml2/
OBJ = ./bin/libubaclogger++.so
INCLUDE_INSTALL = /usr/local/include/ubaclogger

all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)
	strip $(OBJ)

install:
	./install.sh

clean:
	rm -f $(OBJ)

