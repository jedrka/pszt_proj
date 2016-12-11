#include <iostream>
#include "SolverDFS.h"
#include "ModelSzachy.h"
#include "StateSzachownica.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

int main() {

    cout<<"sss"<<endl;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::Font font;
    if (!font.loadFromFile("../ArialN.TTF"))
    {
        // error...
    }

    sf::Text text;
    text.setFont(font);
    text.setString("hehe");


    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        window.draw(text);
        window.display();
    }
    return 0;
/*
    ModelSzachy ms(5);
    SolverDFS dfs;

    dfs.setModel(ms);
    shared_ptr<State> s = dfs.solve();
*/
    return 0;
}
