#include "Game.h"
#include <SFML/Graphics.hpp>
#include "menu.h"
enum class  GameState {Menu, Playing, Scores, Exiting};


int main() {
    //sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Arkanoid");
    //Menu menu(window.getSize().x, window.getSize().y);
    //Game game; // Za³aduje bloki, paletkê itp.
    //GameState currentState = GameState::Menu;
    //Game Game;
    //void run();
    //void processEvents();
    ////game.run();
    //return 0;
	int menu_selected_flag = 0;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML demo");// utworz okno
	Menu menu(window.getSize().x, window.getSize().y);
	// petla wieczna - dopoki okno jest otwarte
	while (window.isOpen())
	{
		// w kazdej iteracji petli sprawdzaj zdarzenia
		sf::Event event;
		while (window.pollEvent(event))
		{
			// jezeli odebrano zdarzenie "Closed" zamknij okno
			if (event.type == sf::Event::Closed)
				window.close();
			//jezeli nacisnieto jakikolwiek przycisk
			if (event.type == sf::Event::KeyPressed)
			{//obsluga menu z poziomu klawiszy (strzalki)
				if (event.key.code == sf::Keyboard::Up)
				{
					myDelay(250);
					menu.przesunG();
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					myDelay(250);
					menu.przesunD();
				}
				if (menu_selected_flag == 0)
				{//uruchamianie procedur na skutek wyboru menu (wybor poziomu menu to ENTER))
					if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 0)
					{
						std::cout << "Uruchamiam gre..." << std::endl;
						menu_selected_flag = 1;
					}

					if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 1)
					{
						std::cout << "Najlepsze wyniki..." << std::endl;
						menu_selected_flag = 1;
					}

					if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 2)
					{
						std::cout << "Koniec gry..." << std::endl;
						menu_selected_flag = 1;
					}

				}


			}
		}



		// wyczysc obszar rysowania
		window.clear();


		// tutaj umiesc procedury rysujace...
		// window.draw(...);
		if (menu_selected_flag == 0)
			menu.draw(window);

		// ostatnia czynnosc - wyswietl okno wraz zawartoscia
		window.display();
	}

	return 0;
}
