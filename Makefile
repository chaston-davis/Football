# Compiler and flags
CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -MMD -MP

# Target executable name
TARGET = football

# Source files and generated object/dependency files
SRCS = footballDriver.cpp football.cpp Quarterback.cpp WideReceiver.cpp TightEnd.cpp RunningBack.cpp Center.cpp Defense.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

# Default target
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: all clean run

# Include auto-generated header dependency rules
-include $(DEPS)

