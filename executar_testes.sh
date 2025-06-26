    #!/bin/bash

    # Caminhos
    ROOT=$(dirname "$0")
    TESTES="$ROOT/testes"
    SAIDAS="$ROOT/saidas"
    EXEC="$ROOT/goianinha"

    # 1. Compilar
    echo "🔧 Compilando projeto com make..."
    make -C "$ROOT" || { echo "❌ Erro ao compilar."; exit 1; }

    # 2. Criar pasta de saída, se não existir
    mkdir -p "$SAIDAS"

    # 3. Executar testes
    echo "🚀 Executando testes..."

    for teste in "$TESTES"/*.g; do
        nome=$(basename "$teste" .g)
        echo "🧪 Testando $nome..."
        "$EXEC" "$teste" > "$SAIDAS/saida_${nome}.txt"
    done

    echo "✅ Todos os testes foram executados. Resultados em: $SAIDAS/"
