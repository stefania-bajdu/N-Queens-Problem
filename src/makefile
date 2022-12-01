CXX = gcc
CXXFLAGS = -g -Wall
ifeq ($(OS), Windows_NT)
    SHARED-LIB = libs.dll
else
    SHARED-LIB = libs.so
endif
EXECUTABLE = queens
BUILD_FOLDER_PATH = ../build/
LIBS_PATH = ./libs

INPUT1 = ./date/input1.txt
INPUT2 = ./date/input2.txt
OUTPUT1 = ./out/out1.txt
OUTPUT2 = ./out/out2.txt

all: build-lib build-exe clean

build-lib:
	@$(CXX) *.c -I$(LIBS_PATH) -shared -fPIC $(CXXFLAGS) -o $(BUILD_FOLDER_PATH)$(SHARED-LIB)

build-exe:
	@$(CXX) *.c -I$(LIBS_PATH) $(CXXFLAGS) -o $(EXECUTABLE)


	@.\$(EXECUTABLE) $(INPUT1) $(OUTPUT1)
	@.\$(EXECUTABLE) $(INPUT2) $(OUTPUT2)

.PHONY: clean 
clean: 	
	@rm -f *.o 
