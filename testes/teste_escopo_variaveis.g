int x;

programa {
    x = 10; // Atribui à variável global

    {
        int x;
        x = 99; // Atribui à variável local
        escreva "Dentro do bloco, x e: ";
        escreva x; // Deve imprimir 99
        novalinha;
    }

    escreva "Fora do bloco, x e: ";
    escreva x; // Deve imprimir 10
    novalinha;
}