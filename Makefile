CXX=g++
CXXFLAGS = -Wall -Wextra -O3 -std=c++20
BUILDDIR = build

%: %.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $< -o $(BUILDDIR)/$@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)