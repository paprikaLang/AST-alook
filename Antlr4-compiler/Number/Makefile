CC=clang++
CXXFLAGS=-I/usr/local/include/antlr4 -c -std=c++1z -Werror
LDFLAGS=-L/usr/local/lib -lantlr4-runtime

BUILD_DIR=output
APP=$(BUILD_DIR)/calc
OBJS=$(BUILD_DIR)/main.o $(BUILD_DIR)/calculationLexer.o $(BUILD_DIR)/calculationParser.o 
SOURCE=main.cpp calculationLexer.cpp calculationParser.cpp
VPATH=./antlr4-runtime
#output/calc : output/main.o output/calculationLexer.o output/calculationParser.o 
$(APP):$(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
$(BUILD_DIR)/%.o: %.cpp
#clang++ -I/usr/local/include/antlr4-runtime -c -std=c++1z -Werror main.cpp -o mai.o
		$(CC) $(CXXFLAGS) $< -o $@

%.d: %.cpp
		@echo "Generating dependencies of $*"
		@set -e; rm -f $@; \
		$(CC) $(CXXFLAGS) -MM $< > $@.$$$$; \
		sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' < $@.$$$$ > $@; \
		rm -f $@.$$$$

include $(SOURCE:.cpp=.d)	

.PHONY: clean
clean:
		-rm -rf $(BUILD_DIR)/*
		-rm *.d