CXX ?= g++ -std=c++11
MKDIR := mkdir -p
CXXFLAGS += `pkg-config --cflags sdl2 SDL2_image`
CXXFLAGS += -Wall -pedantic
LDFLAGS := `pkg-config --libs sdl2 SDL2_image`
OUT := bin/factorygame
OBJS := $(patsubst src/%.cpp,obj/%.o, $(wildcard src/*.cpp))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: build

build: $(OUT)

-include $(DEPS)

clean:
	rm -rf $(OUT) $(OBJS)

$(OUT): $(OBJS)
	@$(MKDIR) $(dir $@)
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $@

obj/%.o: src/%.cpp
	@$(MKDIR) $(dir $@)
	$(CXX) $< $(CXXFLAGS) -c -MD -o $@
