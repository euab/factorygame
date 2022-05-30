CXX ?= g++
MKDIR := mkdir -p

INCLUDE := ./src

CXXFLAGS += `pkg-config --cflags sdl2 SDL2_image`
CXXFLAGS += -Wall -pedantic -std=c++14 -I $(INCLUDE)
LDFLAGS := `pkg-config --libs sdl2 SDL2_image`
OUT := bin/factorygame

SRCS_ENGINE := $(wildcard src/engine/*.cpp) \
			   $(wildcard src/engine/io/*.cpp) \
			   $(wildcard src/engine/generation/*.cpp) \
			   $(wildcard src/engine/legacy/*.cpp) \
			   $(wildcard src/engine/scene/*.cpp)

SCRS_GAME := $(wildcard src/factorygame/*.cpp)

SRCS_MAIN := $(wildcard src/main/*.cpp)

SRCS := $(SRCS_ENGINE) $(SCRS_GAME) $(SRCS_MAIN)

OBJS := $(patsubst src/%.cpp,obj/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: build

build: $(OUT)

-include $(DEPS)

clean:
	$(RM) -rf $(OUT) $(OBJS)

$(OUT): $(OBJS)
	@$(MKDIR) $(dir $@)
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $@

obj/%.o: src/%.cpp
	@$(MKDIR) $(dir $@)
	$(CXX) $< $(CXXFLAGS) -c -MD -o $@
