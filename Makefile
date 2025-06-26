# Makefile revisado para o compilador Goianinha

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -D_POSIX_C_SOURCE=200809L
LDFLAGS = -lm # Adicionado para linkar a biblioteca matemática, se necessário no futuro

# --- ARQUIVOS FONTE ---
SRC_DIR = .
SRC = $(SRC_DIR)/analisador_sintatico/main.c \
      $(SRC_DIR)/analisador_sintatico/goianinha.tab.c \
      $(SRC_DIR)/analisador_sintatico/lex.yy.c \
      $(SRC_DIR)/ast/ast.c \
      $(SRC_DIR)/tabela_simbolos/tabela_simbolos.c \
      $(SRC_DIR)/analisador_semantico/semantico.c \
      $(SRC_DIR)/gerador_codigo/gerador.c

TARGET = goianinha

# --- ARQUIVOS DE TESTE ---
TEST_DIR = testes
SAIDA_DIR = saidas
MIPS_DIR = MIPS

# Encontra todos os arquivos de teste com a extensão .g
# IMPORTANTE: Renomeie seus arquivos de teste de .txt para .g se ainda não o fez
TEST_FILES := $(wildcard $(TEST_DIR)/*.g)

# --- ALVOS PRINCIPAIS ---

# Alvo padrão: compila o programa. Uso: 'make' ou 'make all'
all: $(TARGET)

# Alvo de teste: primeiro compila o programa e depois executa todos os testes. Uso: 'make test'
test: all
	@echo "--- Executando todos os testes ---"
	# Garante que os diretórios de saída existam
	@mkdir -p $(SAIDA_DIR)
	@mkdir -p $(MIPS_DIR)
	# Loop que executa o compilador para cada arquivo de teste
	@for test_file in $(TEST_FILES); do \
		base_name=$$(basename $$test_file .g); \
		echo "Executando teste: $$test_file"; \
		./$(TARGET) $$test_file $(MIPS_DIR)/saida$$base_name.asm > $(SAIDA_DIR)/saida$$base_name.txt; \
	done
	@echo "--- Fim dos testes ---"

# --- REGRAS DE COMPILAÇÃO ---

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# --- REGRAS DE GERAÇÃO (Bison/Flex) ---

analisador_sintatico/goianinha.tab.c analisador_sintatico/goianinha.tab.h: analisador_sintatico/goianinha.y
	bison -d -o analisador_sintatico/goianinha.tab.c analisador_sintatico/goianinha.y

analisador_sintatico/lex.yy.c: analisador_sintatico/goianinha.l analisador_sintatico/goianinha.tab.h
	flex -o analisador_sintatico/lex.yy.c analisador_sintatico/goianinha.l

# --- LIMPEZA ---
clean:
	@echo "Limpando arquivos gerados..."
	rm -f $(TARGET)
	rm -f analisador_sintatico/lex.yy.c analisador_sintatico/goianinha.tab.c analisador_sintatico/goianinha.tab.h
	rm -rf $(SAIDA_DIR)
	rm -rf $(MIPS_DIR)
	@echo "Limpeza concluída."

# Declara alvos que não são arquivos
.PHONY: all test clean
