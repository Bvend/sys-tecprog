#include "Principal.h"
#include <time.h>
#include <Windows.h>

Principal::Principal():
Eisten(14, 3, 1879, "Eisten"),
Newton(4, 1, 1643, "Natanzinho")
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	diaAtual = st.wDay;
	mesAtual = st.wMonth;
	anoAtual = st.wYear;

	UTFPR.setNome("UTFPR");

	Eisten.setUnivFiliado(&UTFPR);

	executar();
}

Principal::~Principal()
{
}

void Principal::executar()
{
	Eisten.calc_imprime_idade(diaAtual, mesAtual, anoAtual);
	Newton.calc_imprime_idade(diaAtual, mesAtual, anoAtual);

	Eisten.ondeTrabalho();
}