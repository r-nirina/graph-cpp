# Compiler options
CXX      = g++
CXXFLAGS  += -g -Wall -std=c++11 -pedantic

# make default
.DEFAULT_GOAL := all

# Source files
SOURCES = 
SOURCES += g-node.cpp
SOURCES += g-edge.cpp
SOURCES += g-graph.cpp

OBJECTS = $(SOURCES:.cpp=.o)

LDFLAGS +=

$(OBJECTS) : %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

CLEAN_OBJECTS = $(OBJECTS)
TARGETS = 


# ------------- test_g_graph -------------

G_GRAPH_SOURCES = test-g-graph.cpp
G_GRAPH_OBJECTS = $(G_GRAPH_SOURCES:.cpp=.o)

test_g_graph.out : $(G_GRAPH_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(G_GRAPH_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(G_GRAPH_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : test_g_graph.out
TARGETS += test_g_graph.out
CLEAN_OBJECTS += $(G_GRAPH_OBJECTS)


# ------------- cleanup -------------

DEPS = $(CLEAN_OBJECTS:.o=.d)

clean:
	@rm -f $(DEPS) $(TARGETS) $(CLEAN_OBJECTS)

-include $(DEPS)