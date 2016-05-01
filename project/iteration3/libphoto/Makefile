#try 1 blah
# CPP_FILES = $(wildcard src/*.cpp)
# OBJ_FILES = $(addprefix build/,$(notdir $(CPP_FILES:.cpp=.o)))
# CC_FLAGS = -c -Wall
#
# all: libphoto.a
#
# libphoto.a: $(OBJ_FILES)
# 	ar rcs lib/$@ $^
#
# build/%.o: src/%.cpp
# 	g++ $(CC_FLAGS) $@ $<

#try 2
# vpath %.cpp /src
# vpath %.o /build
# vpath %.h /include
# vpath %.a /lib
# CPP_FILES = $(wildcard *.cpp)
# OBJ_FILES = $(patsubst %.c,%.o, $(CPP_FILES))
#
# all: libphoto.a
#
# libphoto.a:

#try 3
# CC = g++
# CFLAGS = -g -c -Wall
# LDFLAGS = -g
#
# SOURCE_DIR = src
# OBJECT_DIR = build
# INCLUDE = -I/include
# LIBRARY = libphoto.a
#
# CPPFILES = $(wildcard $(SOURCE_DIR)/*.cpp)
# OBJFILES = $(addprefix $(OBJECT_DIR)/,  $(notdir $(CPPFILES:.cpp=.o)))
#
# all: setup $(LIBRARY)
#
# setup: | $(OBJECT_DIR)
#
# $(OBJECT_DIR):
# 	mkdir -p $(OBJECT_DIR)
#
# $(LIBRARY): $(OBJFILES)
# 	ar rcs $(LIBRARY) $(OBJFILES)
#
# $(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp
# 	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $<
#
# clean:
# 	\rm -rf $(OBJECT_DIR) $(EXECUTABLE)

#try 4
# CC = g++
# CFLAGS= -c -Wall
# OBJ_DIR = build
#
# all: libphoto.a
#
# lib/libphoto.a: BaseGfxApp.o Blur.o BlurFilter.o CalligraphyPen.o Channels.o ColorData.o ComicBook.o ConvolutionFilter.o EdgeDetection.o Emboss.o Eraser.o Filter.o Highlighter.o IJPGHandler.o ImageHandler.o IPNGHandler.o MotionBlur.o Pen.o PixelBuffer.o Quantize.o Saturate.o Sharpen.o SprayCan.o Threshold.o Tool.o TStamp.o
# 	ar rcs libphoto.a BaseGfxApp.o Blur.o BlurFilter.o CalligraphyPen.o Channels.o ColorData.o ComicBook.o ConvolutionFilter.o EdgeDetection.o Emboss.o Eraser.o Filter.o Highlighter.o IJPGHandler.o ImageHandler.o IPNGHandler.o MotionBlur.o Pen.o PixelBuffer.o Quantize.o Saturate.o Sharpen.o SprayCan.o Threshold.o Tool.o TStamp.o
#
# $(OBJ_DIR)/BaseGfxApp.o: BaseGfxApp.cpp
# 	$(CC) $(CFLAGS) BaseGfxApp.o BaseGfxApp.cpp
#
# $(OBJ_DIR)/Blur.o: Blur.cpp
# 	$(CC) $(CFLAGS) Blur.o Blur.cpp
#
# $(OBJ_DIR)/BlurFilter.o: BlurFilter.cpp
# 	$(CC) $(CFLAGS) BlurFilter.o BlurFilter.cpp
#
# $(OBJ_DIR)/CalligraphyPen.o: CalligraphyPen.cpp
# 	$(CC) $(CFLAGS) CalligraphyPen.o CalligraphyPen.cpp
#
# $(OBJ_DIR)/Channels.o: Channels.cpp
# 	$(CC) $(CFLAGS) Channels.o Channels.cpp
#
# $(OBJ_DIR)/ColorData.o: ColorData.cpp
# 	$(CC) $(CFLAGS) ColorData.o ColorData.cpp
#
# $(OBJ_DIR)/ComicBook.o: ComicBook.cpp
# 	$(CC) $(CFLAGS) ComicBook.o ComicBook.cpp
#
# $(OBJ_DIR)/ConvoltionFilter.o: ConvoltionFilter.cpp
# 	$(CC) $(CFLAGS) ConvoltionFilter.o ConvoltionFilter.cpp
#
# $(OBJ_DIR)/EdgeDetection.o: EdgeDetection.cpp
# 	$(CC) $(CFLAGS) EdgeDetection.o EdgeDetection.cpp
#
# $(OBJ_DIR)/Emboss.o: Emboss.cpp
# 	$(CC) $(CFLAGS) Emboss.o Emboss.cpp
#
# $(OBJ_DIR)/Eraser.o: Eraser.cpp
# 	$(CC) $(CFLAGS) Eraser.o Eraser.cpp
#
# $(OBJ_DIR)/Filter.o: Filter.cpp
# 	$(CC) $(CFLAGS) Filter.o Filter.cpp
#
# $(OBJ_DIR)/Highlighter.o: Highlighter.cpp
# 	$(CC) $(CFLAGS) Highlighter.o Highlighter.cpp
#
# $(OBJ_DIR)/IJPGHandler.o: IJPGHandler.cpp
# 	$(CC) $(CFLAGS) IJPGHandler.o IJPGHandler.cpp
#
# $(OBJ_DIR)/ImageHandler.o: ImageHandler.cpp
# 	$(CC) $(CFLAGS) ImageHandler.o ImageHandler.cpp
#
# $(OBJ_DIR)/IPNGHandler.o: IPNGHandler.cpp
# 	$(CC) $(CFLAGS) IPNGHandler.o IPNGHandler.cpp
#
# $(OBJ_DIR)/MotionBlur.o: MotionBlur.cpp
# 	$(CC) $(CFLAGS) MotionBlur.o MotionBlur.cpp
#
# $(OBJ_DIR)/Pen.o: Pen.cpp
# 	$(CC) $(CFLAGS) Pen.o Pen.cpp
#
# $(OBJ_DIR)/PixelBuffer.o: PixelBuffer.cpp
# 	$(CC) $(CFLAGS) PixelBuffer.o PixelBuffer.cpp
#
# $(OBJ_DIR)/Quantize.o: Quantize.cpp
# 	$(CC) $(CFLAGS) Quantize.o Quantize.cpp
#
# $(OBJ_DIR)/Saturate.o: Saturate.cpp
# 	$(CC) $(CFLAGS) Saturate.o Saturate.cpp
#
# $(OBJ_DIR)/Sharpen.o: Sharpen.cpp
# 	$(CC) $(CFLAGS) Sharpen.o Sharpen.cpp
#
# $(OBJ_DIR)/SprayCan.o: SprayCan.cpp
# 	$(CC) $(CFLAGS) SprayCan.o SprayCan.cpp
#
# $(OBJ_DIR)/Threshold.o: Threshold.cpp
# 	$(CC) $(CFLAGS) Threshold.o Threshold.cpp
#
# $(OBJ_DIR)/Tool.o: Tool.cpp
# 	$(CC) $(CFLAGS) Tool.o Tool.cpp
#
# $(OBJ_DIR)/TStamp.o: TStamp.cpp
# 	$(CC) $(CFLAGS) TStamp.o TStamp.cpp
#
# $(OBJ_DIR)/XPen.o: XPen.cpp
# 	$(CC) $(CFLAGS) XPen.o Xpen.cpp

#try 5
CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp,build/%.o,$(CPP_FILES))
CXXFLAGS = -c -Wall

all: prereqs lib/libphoto.a

lib/libphoto.a: $(OBJ_FILES)
	ar rcs $@ $^

build/%.o: src/%.cpp
	g++ $(CXXFLAGS) -o $@ $<

prereqs:
	mkdir -p lib
	mkdir -p build

.PHONY: prereqs

clean:
	rm  $(OBJ_FILES) lib/libphoto.a
