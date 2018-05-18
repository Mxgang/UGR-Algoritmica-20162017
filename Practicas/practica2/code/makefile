###############################################
#
# 	AUTOR: ALFONSO SOTO LOPEZ
#
# 	GRADO EN INGENIERIA INFORMATICA UGR
#
################################################

SRC = src
BIN = bin
OBJ = obj
LIB = lib
INC = include
DATA = data

CXX = g++ -std=c++11
CPPFLAGS = -Wall -g -I$(INC) -o 

SRCS = $(wildcard $(SRC)/*.cpp)
SRC_PROGS = $(patsubst %.cpp,%,$(SRCS))
PROGS = $(patsubst $(SRC)%,$(BIN)%,$(SRC_PROGS))

#============================================================
#=====================   COMPILACION   ======================
#============================================================

all: $(PROGS)

$(BIN)/%: $(SRC)/%.cpp
	$(info )
	$(info *******************************************)
	$(info Compilando [${@}])
	$(info *******************************************)
	$(CXX) $(CPPFLAGS) $@ $^ 

