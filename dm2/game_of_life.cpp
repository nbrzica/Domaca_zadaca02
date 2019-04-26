#include "game_of_life.h"
#include <time.h>

bool game_of_life::slucajna_vrijednost()
{
	return (rand() % 100) < 25;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	int brojac = 0;

	//prvi red
	if (i == 0) 
	{
		if (j == 0) {
			if (_generacija[i][j + 1])
			{
				brojac++;
			}
			if (_generacija[i + 1][j + 1])
			{
				brojac++;
			}
			if (_generacija[i + 1][j])
			{
				brojac++;
			}

		}

		else if (j == (STUPACA - 1))
		{
			if (_generacija[i][j - 1])
			{
				brojac++;
			}
			if (_generacija[i + 1][j - 1])
			{
				brojac++;
			}
			if (_generacija[i + 1][j])
			{
				brojac++;
			}
		}

		else
		{
			if (_generacija[i][j - 1])
			{
				brojac++;
			}
			if (_generacija[i + 1][j - 1])
			{
				brojac++;
			}
			if (_generacija[i + 1][j])
			{
				brojac++;
			}
			if (_generacija[i + 1][j + 1])
			{
				brojac++;
			}
			if (_generacija[i][j + 1])
			{
				brojac++;
			}
		}

		
	}

	// zadnji redak

	else if (i == (REDAKA - 1))
	{
		if (j == 0) {
			if (_generacija[i - 1][j])
			{
				brojac++;
			}

			if (_generacija[i - 1][j + 1])
			{
				brojac++;
			}

			if (_generacija[i][j + 1])
			{
				brojac++;
			}

		}

		else if (j == (STUPACA - 1))
		{
			if (_generacija[i][j - 1])
			{
				brojac++;
			}

			if (_generacija[i - 1][j - 1])
			{
				brojac++;
			}

			if (_generacija[i - 1][j])
			{
				brojac++;
			}
		}

		else
		{
			if (_generacija[i][j - 1])
			{
				brojac++;
			}

			if (_generacija[i - 1][j - 1])
			{
				brojac++;
			}

			if (_generacija[i - 1][j])
			{
				brojac++;
			}

			if (_generacija[i - 1][j + 1])
			{
				brojac++;
			}

			if (_generacija[i][j + 1])
			{
				brojac++;
			}
		}


	}

	//prvi stupac

	else if (j == 0)
	{
		if (_generacija[i - 1][j])
		{
			brojac++;
		}

		if (_generacija[i - 1][j + 1])
		{
			brojac++;
		}

		if (_generacija[i][j + 1])
		{
			brojac++;
		}

		if (_generacija[i + 1][j + 1])
		{
			brojac++;
		}

		if (_generacija[i + 1][j])
		{
			brojac++;
		}
	}


	//zadnji stupac

	else if (j == (STUPACA - 1))
	{
			if (_generacija[i - 1][j])
			{
				brojac++;
			}

			if (_generacija[i - 1][j - 1])
			{
				brojac++;
			}

			if (_generacija[i][j - 1])
			{
				brojac++;
			}

			if (_generacija[i + 1][j - 1])
			{
				brojac++;
			}

			if (_generacija[i + 1][j])
			{
				brojac++;
			}
	}

	//ostala polja

	else
	{
		if (_generacija[i - 1][j - 1])
		{
			brojac++;
		}

		if (_generacija[i - 1][j])
		{
			brojac++;
		}

		if (_generacija[i - 1][j + 1])
		{
			brojac++;
		}

		if (_generacija[i][j + 1])
		{
			brojac++;
		}

		if (_generacija[i][j - 1])
		{
			brojac++;
		}

		if (_generacija[i + 1][j + 1])
		{
			brojac++;
		}

		if (_generacija[i + 1][j - 1])
		{
			brojac++;
		}

		if (_generacija[i + 1][j])
		{
			brojac++;
		}


	}

	
	if (_generacija[i][j]) {

		if ((brojac == 2) || (brojac == 3))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		if (brojac == 3) {
			return true;
		}
		else
		{
			return false;
		}
	}


}

game_of_life::game_of_life()
{
	srand(time(NULL));
	for (int x = 0; x < REDAKA; x++)
	{
		for (int y = 0; y < STUPACA; y++)
		{
			this->_generacija[x][y] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{  
	for (int x = 0; x < REDAKA; x++)
	{
		for (int y = 0; y < STUPACA; y++)
		{

			
			this->_sljedeca_generacija[x][y] = celija_zauzeta(x, y);


		}
	}


	for (int x = 0; x < REDAKA; x++)
	{
		for (int y = 0; y < STUPACA; y++)
		{


			this->_generacija[x][y] = _sljedeca_generacija[x][y];


		}
	}


}

void game_of_life::iscrtaj()
{
	for (int x = 0; x < REDAKA; x++)
	{
		for (int y = 0; y < STUPACA; y++)
		{
			if (_generacija[x][y]) {
				cout << "*";
			}
			else
			{
				cout << "_";
			}
			if (y == (STUPACA - 1)) {
				cout << endl;
			}
		}
	}
}
