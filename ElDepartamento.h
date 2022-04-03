#pragma once

#include <stdio.h>

class Departamento;

class ElDepartamento
{
private:
	Departamento* pDpto;
	ElDepartamento* proxElDpto;
	ElDepartamento* prevElDpto;

public:
	// Construtora e Destrutora
	ElDepartamento();
	~ElDepartamento();

	void setPDpto(Departamento* pd);
	Departamento* getPDpto();

	void setProxElDpto(ElDepartamento* pED);
	ElDepartamento* getProxElDpto();
	void setPrevElDpto(ElDepartamento* pED);
	ElDepartamento* getPrevElDpto();
};