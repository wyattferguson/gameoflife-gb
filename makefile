PROJECTNAME = gameoflife

CC = lcc

CFLAGS = -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf--debug -c

LDFLAGS = -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -Wf--debug

SRC = src/main.c src/board.c src/font.c src/screens.c src/utils.c

OBJ = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRC))

BUILD_DIR = build

$(BUILD_DIR)/%.o: src/%.c

	$(CC) $(CFLAGS) -o $@ $<

all: $(BUILD_DIR)/$(PROJECTNAME).gb

$(PROJECTNAME).gb: $(OBJ)

	$(CC) $(LDFLAGS) -o $@ $(OBJ)
