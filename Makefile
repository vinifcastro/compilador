CC = gcc

SRC = analisador_sintatico/main.c \
      analisador_sintatico/goianinha.tab.c \
      analisador_sintatico/lex.yy.c \
      ast/ast.c \
      tabela_simbolos/tabela_simbolos.c \
      analisador_semantico/semantico.c \
      gerador_codigo/gerador.c

TESTES = testes
SAIDAS = saidas
MIPS = MIPS

TEST_FILES := $(wildcard $(TESTES)/*.g)
MIPS_FILES := $(patsubst $(TESTES)/%.g,$(MIPS)/saida%.asm,$(TEST_FILES))
SAIDA_FILES := $(patsubst $(TESTES)/%.g,$(SAIDAS)/saida%.txt,$(TEST_FILES))

all: goianinha $(MIPS) $(SAIDAS) $(MIPS_FILES) $(SAIDA_FILES)

goianinha: $(SRC)
	$(CC) -Wall -Wextra -std=c99 -D_POSIX_C_SOURCE=200809L -o goianinha $(SRC)

analisador_sintatico/goianinha.tab.c analisador_sintatico/goianinha.tab.h: analisador_sintatico/goianinha.y
	bison -d -o analisador_sintatico/goianinha.tab.c analisador_sintatico/goianinha.y

analisador_sintatico/lex.yy.c: analisador_sintatico/goianinha.l analisador_sintatico/goianinha.tab.h
	flex -o analisador_sintatico/lex.yy.c analisador_sintatico/goianinha.l

# Regra: executa cada teste, gera MIPS/saidaX.asm e a saída do terminal em saidas/saidaX.txt
$(MIPS)/saida%.asm $(SAIDAS)/saida%.txt: $(TESTES)/%.g goianinha | $(MIPS) $(SAIDAS)
	-./goianinha $< $(MIPS)/saida$*.asm > $(SAIDAS)/saida$*.txt

$(MIPS):
	mkdir -p $(MIPS)
$(SAIDAS):
	mkdir -p $(SAIDAS)

clean:
	rm -f goianinha *.o analisador_sintatico/lex.yy.c analisador_sintatico/goianinha.tab.* $(SAIDAS)/* $(MIPS)/*

.PHONY: all clean
