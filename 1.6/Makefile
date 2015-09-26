# -*- tab-width: 4 -*-

SOURCE	:= $(wildcard *.cpp)
EXECUTE	:= $(patsubst %.cpp,%.exe,$(SOURCE))

CXX			:= clang++
CXXFLAGS	:= -Wall -Weffc++ -std=c++98

%.exe : %.cpp $(wildcard *.hpp)
	# create: $@
	$(CXX) $(CXXFLAGS) $< -o $@

check: $(EXECUTE)
	@for e in $^ ; do \
		if [ -e $${e} ]; then \
			printf "# execute: $${e}\n"; \
			./$${e}; \
		fi \
	done

all: $(EXECUTE)

clean:
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check all clean
