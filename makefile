# For windows, you need to modify ALLEGRO_PATH and environment variable.
ALLEGRO_PATH := ../allegro

OUT := game
CC := g++
ALLEGRO_FLAGS_RELEASE := -I$(ALLEGRO_PATH)/include -L$(ALLEGRO_PATH)/lib/liballegro_monolith.dll.a
ALLEGRO_DLL_PATH_RELEASE := $(ALLEGRO_PATH)/lib/liballegro_monolith.dll.a
ALLEGRO_FLAGS_DEBUG := -I$(ALLEGRO_PATH)/include -L$(ALLEGRO_PATH)/lib/liballegro_monolith-debug.dll.a
ALLEGRO_DLL_PATH_DEBUG := $(ALLEGRO_PATH)/lib/liballegro_monolith-debug.dll.a

CXXFLAGS := -Wall -std=c++17 -O2
SOURCE := $(wildcard *.cpp */*.cpp)
OBJ := $(patsubst %.cpp, %.o, $(notdir $(SOURCE)))
RM_OBJ = 
RM_OUT = 
ifeq ($(OS),Windows_NT) # Windows OS
	RM_OBJ = $(foreach name, $(OBJ), del $(name) & )
	ifeq ($(suffix $(OUT)),)
		RM_OUT = del $(OUT).exe
	else
		RM_OUT = del $(OUT)
	endif
else # Mac OS / Linux
	RM_OBJ = rm $(OBJ)
	RM_OUT = rm $(OUT)
	UNAME_S := $(shell uname -s)
	ALLEGRO_LIBRARIES := allegro-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_dialog-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5
	ALLEGRO_FLAGS_RELEASE := $(shell pkg-config --cflags --libs "$(ALLEGRO_LIBRARIES) <= 5.2.7") -lallegro -lallegro_main
	ALLEGRO_FLAGS_DEBUG := $(ALLEGRO_FLAGS_RELEASE)
	ALLEGRO_DLL_PATH_RELEASE :=
	ALLEGRO_DLL_PATH_DEBUG := $(ALLEGRO_DLL_PATH_RELEASE)
	ifeq ($(UNAME_S),Darwin) # Mac OS
	endif
endif

debug:
	$(CC) -c -g $(CXXFLAGS) $(SOURCE) $(ALLEGRO_FLAGS_DEBUG)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ) $(ALLEGRO_FLAGS_DEBUG) $(ALLEGRO_DLL_PATH_DEBUG)
	$(RM_OBJ)

release:
	$(CC) -c $(CXXFLAGS) $(SOURCE) $(ALLEGRO_FLAGS_RELEASE)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ) $(ALLEGRO_FLAGS_RELEASE) $(ALLEGRO_DLL_PATH_RELEASE)
	$(RM_OBJ)

clean:
	$(RM_OUT)
