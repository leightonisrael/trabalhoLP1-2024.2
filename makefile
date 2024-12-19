# makefile

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -g -Iheaders -IleituraEscrita/headers

# Diretórios
SRCDIR = .
OBJDIR = obj

# Arquivos de origem
SRC = $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/classes/*.cpp $(SRCDIR)/leituraEscrita/classes/*.cpp)

# Arquivos objeto
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Alvo final
TARGET = main

# Regras
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: clean
