CXX ?= g++ -std=c++14
MKDIR := mkdir -p

INCLUDE := ./src

CXXFLAGS += `pkg-config --cflags sdl2 SDL2_image`
CXXFLAGS += -Wall -pedantic -std=c++14 -I $(INCLUDE)
LDFLAGS := `pkg-config --libs sdl2 SDL2_image`
OUT := bin/factorygame

SRCS := $(wildcard src/*.cpp) \
		$(wildcard src/io/*.cpp) \
		$(wildcard src/generation/*.cpp) \
		$(wildcard src/scene/*.cpp)

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
