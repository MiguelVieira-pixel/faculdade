# RESUMO PARA A PROVA - Estrutura de Dados

## 1. STRUCT (Estrutura)

### O que é?
Uma struct agrupa diferentes tipos de dados em uma única entidade.

### Sintaxe básica:
```c
typedef struct {
    tipo var1;
    tipo var2;
} NomeStruct;
```

### Exemplo:
```c
typedef struct {
    char nome[30];
    int cpf;
    int idade;
} Pessoa;

Pessoa p = {"Miguel", 123456789, 19};
```

### Pontos importantes:
- Acesso com ponto: `p.nome`, `p.idade`
- Array de structs: `Pessoa pessoas[10];`
- Atribuição direta: `pessoas[0] = p;`

---

## 2. BUBBLE SORT (Ordenação por Bolha)

### Como funciona?
- Compara elementos **adjacentes**
- Se um é maior que o próximo, **troca**
- Repete até estar ordenado

### Passos:
1. Passa pelo array
2. Compara pares adjacentes
3. Troca se necessário
4. O "maior" "boia" para o final

### Complexidade:
- Melhor caso: O(n) - com otimização
- Pior caso: O(n²)
- Caso médio: O(n²)

### Otimização:
Usar flag para detectar se já está ordenado:
```c
int trocou = 0;
if (arr[j] > arr[j+1]) {
    // troca
    trocou = 1;
}
if (!trocou) break; // já está ordenado!
```

---

## 3. RECURSÃO

### O que é?
Uma função que chama a **si mesma** com parâmetros menores.

### OBRIGATÓRIO ter:
1. **CASO BASE** - quando para de chamar a si mesma
2. **CASO RECURSIVO** - chama a si mesma com valores menores

### Exemplo simples - Fatorial:
```c
int fatorial(int n) {
    if (n <= 1) return 1;        // CASO BASE
    return n * fatorial(n - 1);  // CASO RECURSIVO
}
```

### Exemplos comuns:
- **Fatorial**: n! = n * (n-1)!
- **Fibonacci**: fib(n) = fib(n-1) + fib(n-2)
- **Soma**: soma(n) = n + soma(n-1)
- **Busca binária**: divide e conquista

### Dicas importantes:
- Sempre tenha um CASO BASE, senão fica infinito!
- Cada chamada recursiva deve se aproximar do caso base
- Recursão usa mais memória que loops (stack)
- Bom para: estruturas recursivas (árvores, grafos)

---

## EXERCÍCIO TÍPICO DE PROVA

Frequentemente combinam os 3 tópicos:

1. Criar uma **struct** com dados
2. Ordenar os dados com **bubble sort**
3. Fazer uma busca ou cálculo com **recursão**

Exemplo: Ordenar alunos por nota e recursivamente calcular a média.

---

## DICAS PARA A PROVA

✓ Leia o enunciado com cuidado
✓ Identifique if é precisa struct, sort e/ou recursão
✓ **Bubble Sort**: sempre 2 loops! (externo e interno)
✓ **Recursão**: não esqueça do CASO BASE!
✓ **Struct**: lembre de usar `typedef`
✓ Teste seu código com exemplos pequenos
✓ Comente seu código

---

## ARQUIVOS DE ESTUDO CRIADOS

1. `bubble_sort_estudo.c` - Exemplos de bubble sort simples e otimizado
2. `recursao_estudo.c` - 6 exemplos de funções recursivas
3. `prova_estudo_completo.c` - Struct + Bubble Sort + Recursão integrados

**Para estudar:** Compile e execute cada arquivo!
```bash
gcc bubble_sort_estudo.c -o bubble
gcc recursao_estudo.c -o recursao
gcc prova_estudo_completo.c -o completo
```

Boa sorte na prova! 🎓
