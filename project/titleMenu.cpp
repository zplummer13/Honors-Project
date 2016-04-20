#include <SFML/Graphics.hpp>
#include "titleMenu.hpp"

TitleMenu::TitleMenu()
{
	onMenu = true;
	screen = 0;
	cooldown = 0;
	setTexts();
	if (!font.loadFromFile("j_d_handcrafted/j.d.ttf")) { /* Nothing */}
}

void TitleMenu::setTexts()
{
	texts.clear();
	if (screen == 0)
	{
		sf::Text title0;
		title0.setString("The Library");
		title0.setFont(font);
		title0.setCharacterSize(80);
		title0.setPosition(80,50);
		title0.setColor(sf::Color::Red);

		sf::Text title1;
		title1.setString("of");
		title1.setFont(font);
		title1.setCharacterSize(80);
		title1.setPosition(250,150);
		title1.setColor(sf::Color::Red);

		sf::Text title2;
		title2.setString("Secrets");
		title2.setFont(font);
		title2.setCharacterSize(80);
		title2.setPosition(150,250);
		title2.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Begin");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(20);
		enterPrompt.setPosition(200,400);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(title0);
		texts.push_back(title1);
		texts.push_back(title2);
		texts.push_back(enterPrompt);
	}
	else if (screen == 1)
	{
		sf::Text text0;
		text0.setString("Waking up in the middle of the \nwoods, a girl finds herself alone. She\nhas no memory of how she got there\nor who she is.");
		text0.setFont(font);
		text0.setCharacterSize(30);
		text0.setPosition(20,20);
		text0.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(enterPrompt);
	}
	else if (screen == 2)
	{
		sf::Text text0;
		text0.setString("Waking up in the middle of the \nwoods, a girl finds herself alone. She\nhas no memory of how she got there\nor who she is.");
		text0.setFont(font);
		text0.setCharacterSize(30);
		text0.setPosition(20,20);
		text0.setColor(sf::Color::Red);

		sf::Text text1;
		text1.setString("Standing in the middle of a clearing,\nshe hears a sound from the perimeter.\nFinding courage, she takes a step\ntowards the noise.");
		text1.setFont(font);
		text1.setCharacterSize(30);
		text1.setPosition(20,200);
		text1.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(text1);
		texts.push_back(enterPrompt);
	}
	else if (screen == 3)
	{
		sf::Text text0;
		text0.setString("Right then, a wolf with eight eyes\njumps out from behind a tree. Reacting\nquickly, the girl flees the clearing,\nputting as much distance between\nherself and the beast as possible.");
		text0.setFont(font);
		text0.setCharacterSize(30);
		text0.setPosition(20,20);
		text0.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(enterPrompt);
	}
	else if (screen == 4)
	{
		sf::Text text0;
		text0.setString("Right then, a wolf with eight eyes\njumps out from behind a tree. Reacting\nquickly, the girl flees the clearing,\nputting as much distance between\nherself and the beast as possible.");
		text0.setFont(font);
		text0.setCharacterSize(30);
		text0.setPosition(20,20);
		text0.setColor(sf::Color::Red);

		sf::Text text1;
		text1.setString("As her feet raced, the girl realizes\nshe forgot her shadow back in the\nclearing. It slipped off.");
		text1.setFont(font);
		text1.setCharacterSize(30);
		text1.setPosition(20,230);
		text1.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(text1);
		texts.push_back(enterPrompt);
	}
	else if (screen == 5)
	{
		sf::Text text0;
		text0.setString("But the wolf was not far behind.\nRunning for her life, she glances back\nand sees the eight-eyed hound\nclosing the gap quickly.");
		text0.setFont(font);
		text0.setCharacterSize(30);
		text0.setPosition(20,20);
		text0.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(enterPrompt);
	}
	else if (screen == 6)
	{
		sf::Text text0;
		text0.setString("But the wolf was not far behind.\nRunning for her life, she glances back\nand sees the eight-eyed hound\nclosing the gap quickly.");
		text0.setFont(font);
		text0.setCharacterSize(30);
		text0.setPosition(20,20);
		text0.setColor(sf::Color::Red);

		sf::Text text1;
		text1.setString("The wolf is almost on her. Its jaw\nhangs open. It lunges forward.\nBut only finds a mouthful of shadow.");
		text1.setFont(font);
		text1.setCharacterSize(30);
		text1.setPosition(20,230);
		text1.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(text1);
		texts.push_back(enterPrompt);
	}
	else if (screen == 7)
	{
		sf::Text text0;
		text0.setString("To her surprise, the girl had swapped\nplaces with her shadow. Using her new\nfound power, she and her shadow\nexplore the woods seeking answers.");
		text0.setFont(font);
		text0.setCharacterSize(30);
		text0.setPosition(20,20);
		text0.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(enterPrompt);
	}
	else if (screen == 8)
	{
		sf::Text text0;
		text0.setString("To her surprise, the girl had swapped\nplaces with her shadow. Using her new\nfound power, she and her shadow\nexplore the woods seeking answers.");
		text0.setFont(font);
		text0.setCharacterSize(30);
		text0.setPosition(20,20);
		text0.setColor(sf::Color::Red);

		sf::Text text1;
		text1.setString("The girl finds a single ghost-guarded\ntower, the Library of Secrets.\nDetermined to find her name, she\nventures inside.");
		text1.setFont(font);
		text1.setCharacterSize(30);
		text1.setPosition(20,230);
		text1.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(text1);
		texts.push_back(enterPrompt);
	}
	else if (screen == 9)
	{
		sf::Text text0;
		text0.setString("Will you?");
		text0.setFont(font);
		text0.setCharacterSize(50);
		text0.setPosition(40,40);
		text0.setColor(sf::Color::Red);

		sf::Text enterPrompt;
		enterPrompt.setString("Press Enter to Continue");
		enterPrompt.setFont(font);
		enterPrompt.setCharacterSize(16);
		enterPrompt.setPosition(220,440);
		enterPrompt.setColor(sf::Color::Red);

		texts.push_back(text0);
		texts.push_back(enterPrompt);
	}
	else
	{
		setOnMenu(false);
	}
}

std::vector<sf::Text> TitleMenu::getTexts()
{
	return texts;
}

void TitleMenu::setScreen(int x)
{
	screen = x;
	setTexts();
}

void TitleMenu::incrementScreen()
{
	++screen;
	setTexts();
}

void TitleMenu::setOnMenu(bool b)
{
	onMenu = b;
}

bool TitleMenu::getOnMenu()
{
	return onMenu;
}

int TitleMenu::getCooldown()
{
	return cooldown;
}

void TitleMenu::setCooldown(int x)
{
	cooldown = x;
}