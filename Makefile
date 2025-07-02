# 📦 Compiler and Flags
CC = gcc
CFLAGS = -Wall

# 📁 Source Files
SOURCES = main.c can.c ecu.c scheduler.c error.c logger.c platform.c

# 📄 Output Executable
EXEC = can_sim.exe

# 🎯 Default target: build the executable
all: $(EXEC)

# 🔨 Compile all source files into the executable
$(EXEC): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXEC)

# ▶️ Run the simulation
run: $(EXEC)
	./$(EXEC)

# 🧹 Clean: remove the executable
clean:
	del $(EXEC)
