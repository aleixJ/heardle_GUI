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
	TEXT("./songs/NO TE HAS IDO Y YA TE EXTRAÑO.wav"),
	TEXT("./songs/– (MENOS).wav"),
	TEXT("./songs/ESTUPIDEZ.wav"),
	TEXT("./songs/X (POR).wav"),
	TEXT("./songs/CORAZÓN SIN VIDA.wav"),
	TEXT("./songs// (DIVIDIDO).wav"),
	TEXT("./songs/CUANDO TE FUISTE.wav"),
	TEXT("./songs/+ (MÁS).wav"),
	TEXT("./songs/SI NO VAS A VOLVER.wav"),
	TEXT("./songs/= (IGUAL).wav"),
	TEXT("./songs/11 RAZONES.wav")
	};

	*segons = { 2,4,7,10,13 };
}


void song::mostrarOpcions()
{

}

bool song::guanyador(int resposta)
{
	if (resposta == m_num)
		return true;
	return false;
}

void song::generarNum()
{
	srand(time(NULL));
	m_num = rand() % MAX_SONG;
}

void song::playSong()
{

	PlaySound(pathList->at(m_num), NULL, SND_ASYNC);
	temps_inicial = time(0);
	while (difftime(time(0), temps_inicial) != segons->at(i_segons))
	{
	}
	PlaySound(TEXT("./songs/void.wav"), NULL, SND_ASYNC);
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

void song::introduccio()
{
}

void song::final(bool win)
{
	//si win es true, mostrem que ha gunyat. En el cas contrari, diuen que ha perdut i revelem la resposta correcte

}

void song::obtenirResposta(int& resposta, bool flag_repetir)
{
	//'flag_repetir' repetir serveix per saber si la resposta te dues opcions (si es '1' per indicar i s'acaba o no) o mes opcions (si es '0' que es per les respostes de songs)
	int res_valid = false;


}