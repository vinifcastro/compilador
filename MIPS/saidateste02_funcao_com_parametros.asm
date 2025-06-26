# variável: a
# variável: b
# variável: resultado
# variável: a
move $t1, $t0
# variável: b
add $t0, $t1, $t0
# variável: a
# variável: b
# atribuição para resultado
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: resultado
# variável: a
move $t1, $t0
# variável: b
add $t0, $t1, $t0
# variável: a
# variável: b
# variável: resultado
# variável: x
# variável: soma
# constante: 3
li $t0, 3
# constante: 4
li $t0, 4
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# variável: soma
# constante: 3
li $t0, 3
# constante: 4
li $t0, 4
# variável: x
move $a0, $t0
li $v0, 1
syscall
# variável: x
