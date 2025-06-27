int x;

programa {
    x = 10; 

    {
        int x;
        x = 99; 
        escreva "Dentro do bloco, x e: ";
        escreva x; 
        novalinha;
    }

    escreva "Fora do bloco, x e: ";
    escreva x; 
    novalinha;
}