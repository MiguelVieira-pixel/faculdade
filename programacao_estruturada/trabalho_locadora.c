#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidadeFitas, totalFitas = 0, fitasAlugadas = 0, fitasAtrasadas = 0, fitaEstragada = 0, reposicao = 0;
    float valorAluguel, faturamentoMensal = 0, faturamentoAnual = 0, multaMes = 0, multaAno = 0;

    printf("\n Digite a quantidade de fitas no total: ");
    scanf("%d", & quantidadeFitas);
    printf("\n Digite o valor do aluguel das fitas: ");
    scanf("%f", & valorAluguel);
    fitasAlugadas = quantidadeFitas / 3;

    //faturamento por mês
    faturamentoMensal = fitasAlugadas * valorAluguel;
    printf("\n Faturamento mensal = %.2f", faturamentoMensal);

    //faturamento por ano
    faturamentoAnual = faturamentoMensal * 12;
    printf("\n Faturamento anual = %.2f", faturamentoAnual);

    //valor ganho com multas por mes
    fitasAtrasadas = fitasAlugadas / 10;
    multaMes =  fitasAtrasadas * (valorAluguel * 0.1);
    printf("\n Valor ganho com multa por mes = %.2f", multaMes);

    //valor ganho com multas por ano
    multaAno = multaMes * 12;
    printf("\n Valor ganho com multa por ano = %.2f", multaAno);

    //quantidade de fitas estragadas
    fitaEstragada = 0.02 * quantidadeFitas;
    printf("\n Quantidade de fita estragada = %d", fitaEstragada);

    //quantidade de reposição
    reposicao = quantidadeFitas / 10;
    printf("\n Quantidade de fitas de reposicao = %d", reposicao);

    // fita total da locadora no final do ano
    totalFitas = quantidadeFitas - fitaEstragada + reposicao;
    printf("\n Quantidade de fitas que a locadora tera no final do ano = %d", totalFitas);
    system("pause > null");
    return 0;
}
