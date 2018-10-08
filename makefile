
TARGET = wavreader.exe
DIR_SOURCE = .\src
DIR_INCLUDE = .\include
DIR_BIN = .\bin
DIR_OBJ = $(DIR_BIN)\obj

SOURCES = \
	$(DIR_SOURCE)\main.cpp\
	$(DIR_SOURCE)\wavreader.cpp\

$(TARGET) : $(SOURCES)
	cl /EHsc /Fe$(DIR_BIN)\$(TARGET) /I$(DIR_INCLUDE) $(SOURCES)


wavreader: $(TARGET)

create_dirs:
	@if not exist $(DIR_BIN) mkdir $(DIR_BIN)
	@if not exist $(DIR_OBJ) mkdir $(DIR_OBJ)

clean:
	@if exist $(DIR_BIN) rmdir /S /Q $(DIR_BIN)
	@if exist $(DIR_OBJ) rmdir /S /Q $(DIR_OBJ)

all: clean create_dirs wavreader