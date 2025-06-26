#ifndef GERADOR_H
#define GERADOR_H

#include "ast.h"
#include <stdio.h>

void gerar_codigo_mips(ASTNode* raiz, FILE* saida);

#endif
