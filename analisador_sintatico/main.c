#include <stdio.h>
#include <stdlib.h>

#include "../includes/ast.h"
#include "../includes/semantico.h"
#include "../includes/gerador.h"

extern int yyparse();
extern FILE* yyin;
extern int yylineno;

ASTNode* ast_raiz; 

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s arquivo_entrada.g [arquivo_saida_mips.asm]\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    yylineno = 1;

    if (yyparse() == 0) {
        printf("✅ Análise sintática concluída com sucesso.\n");

        printf("\n📍 Árvore Sintática Abstrata (AST):\n");
        imprimir_ast(ast_raiz, 0);

        printf("\n🔎 Iniciando análise semântica:\n");
        analisar_semantica(ast_raiz);

        printf("\n⚙️  Gerando código MIPS...\n");
        const char* nome_saida = (argc >= 3) ? argv[2] : "saida.asm";
        FILE* out = fopen(nome_saida, "w");
        if (!out) {
            perror("Erro ao abrir arquivo de saída MIPS");
            liberar_ast(ast_raiz);
            fclose(yyin);
            return 1;
        }
        gerar_codigo_mips(ast_raiz, out);
        fclose(out);
        printf("✅ Código MIPS gerado com sucesso: %s\n", nome_saida);

        liberar_ast(ast_raiz);
    } else {
        printf("❌ Falha na análise sintática.\n");
    }

    fclose(yyin);
    return 0;
}
