#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>

#define MAX_SONG 11

ref class song
{
private:

	std::vector<LPCWSTR>* pathList = new std::vector<LPCWSTR>;

	int m_num;

	//per poder gestionar el tema de segons de reproduccio i vides.
	std::vector <int>* segons = new std::vector<int>;
	int i_segons = 0;
	int pistes = 0;
	int max_pistes = 4;
	time_t temps_inicial;
	double seconds_since_start;

public:
	std::vector<std::string>* songsList = new std::vector<std::string>;

	song();
	void mostrarOpcions();
	bool guanyador(std::string resposta);
	void generarNum();
	int segonsDisponibles() { return segons->at(i_segons); }
	void playSong();
	bool mesSegons();
	void introduccio();
	void final(bool end);
	void obtenirResposta(int& resposta, bool flag_repetir);
	int obtenirMaxPistes() { return max_pistes; }
	int obtenirPistesDis() { return pistes; }
};