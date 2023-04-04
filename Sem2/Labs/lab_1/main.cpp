#include <iostream>
#include <thread>
#include <animation.h>

void textOutput(const animatedText& object){
    sf::RenderWindow window(sf::VideoMode(800, 600), "M.T.Cool!");
    sf::Text SFMLText;
    sf::Font mainFont;
    if (mainFont.loadFromFile("ext\\res\\consola.ttf")){
        SFMLText.setFont(mainFont);
        SFMLText.setCharacterSize(25);
        SFMLText.setFillColor(sf::Color::White);
        SFMLText.setStyle(sf::Text::Regular);
        SFMLText.setPosition(315,150);
    }
    else{
        std::cout << "FontUploadFail" << std::endl;
    }
    unsigned short index = 0;
    std::string tempText;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        if (index < object.getText().length()){
            for (int i = 0; i <= index; i++){
                tempText += object.getText()[i];
            }
            SFMLText.setString(tempText);
            tempText = "";
            index++;
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(object.getInterval()));
        window.draw(SFMLText);
        window.display();
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    animatedText test(13, "Hello, world!");
    textOutput(test);
    return 0;
}
