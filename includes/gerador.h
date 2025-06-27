#ifndef GERADOR_H
#define GERADOR_H

#include "ast.h"
#include <stdio.h>

// Função principal que inicia a geração de código
void gerar_codigo_mips(ASTNode* raiz, FILE* saida);

#endif