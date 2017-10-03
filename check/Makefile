TARGET_EXEC ?= a.out

# ビルドディレクトリとソースディレクトリ
BUILD_DIR ?= ./build
SRC_DIRS ?= ./

CXX = g++

#SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
#SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
SRCS := $(shell ls $(SRC_DIRS) | grep .cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

ETC_INC := $()

#INC_DIRS := $(shell find $(SRC_DIRS) -type d)
#INC_DIRS := $(shell find $(SRC_DIRS) -type d -name '.git' -name 'build' -prune -o -type d  -print)
INC_DIRS := $(SRC_DIRS)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# リンカ用オプション
LDFLAGS := $(shell sdl2-config --libs) -lSDL2_ttf -lSDL2_image #-lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

# コンパイルオプション
#CXXFLAGS := -Wall -Wextra -g -std=c++14 -DDEBUG
CXXFLAGS := -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -g -std=c++14 -DDEBUG

# プリプロセッサ用オプション
CPPFLAGS ?= $(INC_FLAGS) $(shell sdl2-config --cflags) -MMD -MP

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(ETC_INC)
#	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(ETC_INC)

# c source
#$(BUILD_DIR)/%.c.o: %.c 
#	mkdir -p $(dir $@)
#	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ $(ETC_INC)
# cpp source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ $(ETC_INC)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)/*

-include $(DEPS)
