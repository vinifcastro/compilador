# variável: a
# variável: b
# variável: a
move $t1, $t0
# variável: b
add $t0, $t1, $t0
# variável: a
# variável: b
# variável: resultado
# variável: c
# constante: 39
li $t0, 39
# atribuição para c
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: c
# constante: 39
li $t0, 39
# variável: soma
# constante: 5
li $t0, 5
# variável: c
# atribuição para resultado
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: resultado
# variável: soma
# constante: 5
li $t0, 5
# variável: c
# variável: resultado
move $a0, $t0
li $v0, 1
syscall
# variável: resultado
