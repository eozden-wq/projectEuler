CXX=g++
CXXFLAGS = -Wall -Wextra -O3 -std=c++20
BUILDDIR = build

TARGETS := $(addprefix $(BUILDDIR)/, $(basename $(wildcard *.cpp)))

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

%: $(BUILDDIR)/%
	@:

$(BUILDDIR)/%: %.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean all run

clean:
	rm -rf $(BUILDDIR)/*

all: $(TARGETS)

run: $(BUILDDIR)/$(filter-out run,$(MAKECMDGOALS))
	@./$(BUILDDIR)/$(filter-out run,$(MAKECMDGOALS))
