.PHONY:clean
SRC_DIR:=./
OBJECT:=$(SRC_DIR)*.cc
INC_DIR:=./
EXE_DIR:=./bin
INCLUDE:=$(INC_DIR)*.h
CC:=g++
FLAGES:=-o
NEW:=-std=c++0x
DEST:=$(EXE_DIR)/stack
$(DEST):$(OBJECT) $(INCLUDE)
	$(CC) $(FLAGES) $@ $(OBJECT) -I $(INC_DIR) $(NEW) 
clean:
	rm -f $(DEST) 

