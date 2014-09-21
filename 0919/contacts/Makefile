
SRC_DIR:=./
OBJECT:=$(SRC_DIR)*.cc
INC_DIR:=./
EXE_DIR:=./bin
INCLUDE:=$(INC_DIR)*.h
CC:=g++
FLAGES:=-o
$(EXE_DIR)/contacts:$(OBJECT) $(INCLUDE)
	$(CC) $(FLAGES) $@ $(OBJECT) -I $(INC_DIR)
