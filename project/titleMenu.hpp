#ifndef TITLEMENU_HPP
#define TITLEMENU_HPP

class TitleMenu
{
	public:
		TitleMenu();
		void setTexts();
		std::vector<sf::Text> getTexts();
		void setScreen(int x);
		void incrementScreen();
		void setOnMenu(bool b);
		bool getOnMenu();
		int getCooldown();
		void setCooldown(int x);

	private:
		bool onMenu;
		int screen;
		std::vector<sf::Text> texts;
		sf::Font font;
		int cooldown;

};

#endif