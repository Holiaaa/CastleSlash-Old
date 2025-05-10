# Makefile config by Holiaaa
# There is my own makefile config when I code programs in C.
# It works for Windows. I don't try it on Linux/MacOS yet.

# :---------------: CONFIG :-----------------: pk t 

CC = gcc
CFLAGS = 
LIB = 

SRC_DIR = source
DATA_DIR = data
BUILD_DIR = build
INCLUDE_DIR = include
LIB_DIR = lib
EXECUTABLE_NAME = castleslash.exe

# :--------------: COMPILING :---------------:

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

# :----------------: RULES :-----------------:

MAKEFILE_VERSION = "1.1"

$(BUILD_DIR)/info.txt:
	@echo "Makefile Holiaaa version $(MAKEFILE_VERSION)"
	@echo "Creating build directory..."
	@mkdir $(BUILD_DIR)
	@touch $@
	@echo "Holiaaa" > $(BUILD_DIR)/info.txt

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(BUILD_DIR)/info.txt
	@echo "Compiling $< ..."
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/%: $(DATA_DIR)/% $(BUILD_DIR)/info.txt
	@echo "Copying $< to $(BUILD_DIR) ..."
	@mkdir -p $(dir $@)
	@cp -r $< $(dir $@)

$(BUILD_DIR)/$(EXECUTABLE_NAME): $(OBJECTS) $(BUILD_DIR)/info.txt $(addprefix $(BUILD_DIR)/, $(notdir $(wildcard $(DATA_DIR)/*)))
	@echo "Link $< ..."
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ -L$(LIB_DIR) $(LIB)
	@powershell rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/info.txt

.PHONY: build
build: $(BUILD_DIR)/$(EXECUTABLE_NAME)

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)
	@echo "Project is clean!"

run:
	@echo "Running $(EXECUTABLE_NAME)"
	@echo "--------------------------------------"
	@cd $(BUILD_DIR) && \
	./$(EXECUTABLE_NAME)

runcmd:
	@echo "Running $(EXECUTABLE_NAME) in a new terminal"
	@echo "--------------------------------------"
	@cd $(BUILD_DIR) && \
	start $(EXECUTABLE_NAME)
