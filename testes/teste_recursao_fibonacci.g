int fib(int n) {
    se (n <= 1) entao
        retorne n;
    senao
        retorne fib(n-1) + fib(n-2);
}

programa {
    int valor;
    valor = 8; // Calcula o 8º número de Fibonacci
    escreva "O fibonacci de ";
    escreva valor;
    escreva " e: ";
    escreva fib(valor);
    novalinha;
}
