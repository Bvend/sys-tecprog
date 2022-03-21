#pragma once

class Universidade
{
private:
	char nome[30];

public:
	// Construtora
	Universidade();
	Universidade(const char *n);
	// Destrutora
	~Universidade();

	void setNome(const char* n);
	char* getNome();
};
