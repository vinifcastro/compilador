# variável: x
# constante: 0
li $t0, 0
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 0
li $t0, 0
# variável: x
# constante: 3
li $t0, 3
# variável: x
# constante: 1
li $t0, 1
# variável: x
move $t1, $t0
# constante: 1
li $t0, 1
add $t0, $t1, $t0
# variável: x
# constante: 1
li $t0, 1
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# variável: x
move $t1, $t0
# constante: 1
li $t0, 1
add $t0, $t1, $t0
# variável: x
# constante: 1
li $t0, 1
