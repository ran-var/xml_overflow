CC = gcc
CFLAGS = -g $(shell xml2-config --cflags)
LDFLAGS = $(shell xml2-config --libs)
TARGET = xml_demo
SOURCES = main.c parser.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
