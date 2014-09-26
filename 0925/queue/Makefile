SRC_DIR:=./
OBJECT:=$(SRC_DIR)*.cc
INC_DIR:=./
EXE_DIR:=./bin
INCLUDE:=$(INC_DIR)*.h
CC:=g++
FLAGES:=-o
$(EXE_DIR)/queue:$(OBJECT) $(INCLUDE)
	$(CC) $(FLAGES) $@ $(OBJECT) -I $(INC_DIR)
