#pragma once

#include <iostream>
#include <vector>

#define MAX_SONG 11

ref class song
{
private:

	std::vector<std::string>* pathList = new std::vector<std::string>;

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
	bool comprovar(std::string resposta);
	void generarNum();
	int getSegons() { return segons->at(i_segons); }
	bool mesSegons();
	void obtenirResposta(int& resposta, bool flag_repetir);
	int getMaxPistes() { return max_pistes; }
	int getPistes() { return pistes; }
	std::string getPathSong() { return pathList->at(m_num); }

};