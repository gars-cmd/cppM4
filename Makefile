#!make -f

CXX=clang++-15
CXXVERSION=c++2a
TIDY=clang-tidy
SOURCE_PATH=sources
OBJECT_PATH=objects
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion -I$(SOURCE_PATH)
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=$(wildcard $(SOURCE_PATH)/*.cpp)
HEADERS=$(wildcard $(SOURCE_PATH)/*.hpp)
OBJECTS=$(subst sources/,objects/,$(subst .cpp,.o,$(SOURCES)))

run: test

testS: TestRunner.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

demo: Demo.o $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o $@

demo2: Demo2.o $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o $@

test: TestRunner.o StudentTest1.o  $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@


tidy:
	$(TIDY) $(HEADERS) $(TIDY_FLAGS) --

valgrind:  test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f $(OBJECTS) *.o test* demo*rm -f $(OBJECTS) *.o test* demo*
