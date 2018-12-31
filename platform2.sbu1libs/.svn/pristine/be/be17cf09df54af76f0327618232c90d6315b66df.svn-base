CPP = g++
CPPFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC
SRC = src/*
LIBS = -lpthread -lssl -lubacsslinterface++
INCLUDE = -I ./include/
OBJ = ./bin/libubacipc++.so
INCLUDE_INSTALL = /usr/local/include/ubacipc

all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)
	strip $(OBJ)

install:
	./install.sh

clean:
	rm -f $(OBJ)
test_var_buff:
	g++ test/test_variable_buffer.cpp -lubacipc++ -o ./test/test_variable_buffer.out
