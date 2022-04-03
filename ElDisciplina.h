#pragma once

#include <stdio.h>

class Disciplina;

class ElDisciplina
{
private:
	Disciplina* pDscp;
	ElDisciplina* proxElDscp;
	ElDisciplina* prevElDscp;

public:
	// Construtora e Destrutora
	ElDisciplina();
	~ElDisciplina();

	void setPDscp(Disciplina* pd);
	Disciplina* getPDscp();

	void setProxElDscp(ElDisciplina* pED);
	ElDisciplina* getProxElDscp();
	void setPrevElDscp(ElDisciplina* pED);
	ElDisciplina* getPrevElDscp();
};