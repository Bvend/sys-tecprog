#pragma once

#include <stdio.h>

class Aluno;

class ElAluno
{
private:
	Aluno* pAluno;
	ElAluno* proxElAluno;
	ElAluno* prevElAluno;

public:
	// Construtora e Destrutora
	ElAluno();
	~ElAluno();

	void setPAluno(Aluno* pa);
	Aluno* getPAluno(void);

	void setProxElAluno(ElAluno* pEA);
	ElAluno* getProxElAluno();
	void setPrevElAluno(ElAluno* pEA);
	ElAluno* getPrevElAluno();
};