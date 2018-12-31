OBJ = ./bin/libsbu2webapp++.so
OBJFILESPATH = ./bin
CPP = g++
CFLAGS = -g --shared -Wall -fstack-protector-all -Wstack-protector -fno-defer-pop -Wformat -Wformat-security -fexceptions -finline-functions -fPIC
INCLUDE = -I ./include/
LOCAL_INCLUDE_PATH = ./include
LIBS = -ljsonparser++ -lubacsslinterface++ -lubachttpclient++
SRC = ./src


OBJFILES := $(patsubst $(SRC)/%.cpp,$(OBJFILESPATH)/%.o,$(wildcard $(SRC)/*.cpp))

OBJ: $(OBJFILES)
	$(CPP) $(CFLAGS) $(OBJFILES) $(LIBS) -o $(OBJ)  


$(OBJFILESPATH)/%.o:$(SRC)/%.cpp $(LOCAL_INCLUDE_PATH)/*.h
ifeq ($(ENV),DEV)
	$(CPP) $(CFLAGS) -c $< -o $@ $(INCLUDE) -DCONFIG_DEVELOPMENT
else
	$(CPP) $(CFLAGS) -c $< -o $@ $(INCLUDE)
endif

clean:
	rm $(OBJFILESPATH)/*
install:
	./install.sh

