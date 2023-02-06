#include "song.h"

song::song()
{
	generarNum();

	songsList->resize(MAX_SONG);
	pathList->resize(MAX_SONG);
	segons->push_back(max_pistes + 1);

	*songsList =
	{
		"NO TE HAS IDO Y YA TE EXTRANO",
		"- (MENOS)",
		"ESTUPIDEZ",
		"X (POR)",
		"CORAZON SIN VIDA",
		"/ (DIVIDIDO)",
		"CUANDO TE FUISTE",
		"+ (MAS)",
		"SI NO VAS A VOLVER",
		"= (IGUAL)",
		"11 RAZONES",
	};

	*pathList =
	{ //es possible que no sigui necesari fer posar el .wav
	"./songs/NO TE HAS IDO Y YA TE EXTRAÑO.wav",
	"./songs/– (MENOS).wav",
	"./songs/ESTUPIDEZ.wav",
	"./songs/X (POR).wav",
	"./songs/CORAZÓN SIN VIDA.wav",
	"./songs// (DIVIDIDO).wav",
	"./songs/CUANDO TE FUISTE.wav",
	"./songs/+ (MÁS).wav",
	"./songs/SI NO VAS A VOLVER.wav",
	"./songs/= (IGUAL).wav",
	"./songs/11 RAZONES.wav"
	};

	*segons = { 2,4,7,10,13 };
}

bool song::comprovar(std::string resposta)
{
	if (resposta == songsList->at(m_num))
		return true;
	return false;
}

void song::generarNum()
{
	srand(time(NULL));
	m_num = rand() % MAX_SONG;
}

bool song::mesSegons()
{
	//aumenta els segons
	//retorna true si es pot fer (si queden pistes) i retorna fals en el cas contrari
	if (pistes < max_pistes)
	{
		pistes++;
		i_segons++;
		return true;
	}
	return false;
}

void song::obtenirResposta(int& resposta, bool flag_repetir)
{
	//'flag_repetir' repetir serveix per saber si la resposta te dues opcions (si es '1' per indicar i s'acaba o no) o mes opcions (si es '0' que es per les respostes de songs)
	int res_valid = false;


}