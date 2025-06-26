int soma(int a, int b) {
    retorne a + b;
}

programa {
    int resultado;
    car c;
    c = 'z';
    
    // Erro aqui: passando um 'car' onde se espera um 'int'.
    resultado = soma(5, c); 

    escreva resultado;
    novalinha;
}