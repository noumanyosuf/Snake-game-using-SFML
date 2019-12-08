## Snake-game-using-SFML

# Intention
There are many GUI framework ie. Qt. But I wanted to learn a new framework and I came across SFML. and I found it very intresting.
I decied to create a small classic game, Snake game.<br/>
I tried to keep classic as atomic as possible and tried to deligate responsibility as un-coupled as possible follwing software design principles.

# About SFML
Simple and Fast Multimedia Library (SFML) SFML provides a simple interface to the various components of your PC, to ease the development of games and multimedia applications. It is composed of five modules: system, window, graphics, audio and network.
To read more about SFML use https://www.sfml-dev.org/ url.<br/>

# About classes
Responsiblity of each class is very distinctly define to avoid any coupling.
Below are the description of the class in the project:<br/>
Cordinate class : holds the X and Y cordinate value. <br/>
Board class : holds the attributes of a board. (and do not paint anything on itself by itself)<br/>
Snake class : hold the length and color of the snake. (also do not paint anything on itself by itself)<br/>
Fruit class : As name suggests it hold the attribute of a fruit ie color in this context.(type of fruit do not matter)<br/>
IMoveGenerator : This is a inteface. This class genrates new/next moves for diffrent entities on the board, in our case snake and fruit.<br/>
SnakeMoveGenerator : This is concrete class of IMoveGenerator. it takes current cordinate and direction of snake to return its new/next cordinates.<br/>
FruitMoveGenerator : This is concrete class of IMoveGenerator. it takes current cordinate of fruit to return its new/next cordinates.<br/>
ICordinateValidator : This is a interface.<br/>
SnakeCordinateValidator : its concrete class of ICordinateValidator, which check if given cordinate is valid or not to procced the game (checks if snakes has touch itself). <br/>
IPainter : This is a inteface.<br/>
SnakePainter : This is concrete class of IMoveGenerator. And this class is responsible to paint the snake onto the RenderWindow.<br/>
FruitPainter : This is concrete class of IMoveGenerator. And this class is responsible to paint the fruit onto the RenderWindow.<br/>
GameOverPainter : This is another concrete class of IMoveGenerator. And this class is responsible to paint the game over text onto the RenderWindow. <br/>
GameManager : This class is moderator of the game and is responsible to start the game. This class is also responsible for validating if new move of the snake is valid to continoue the game or if next/new fruit needs to updated.<br/>

Below is the overview of the class diagram (please note that relationship between classes are not defined completely in the below diagram)<br/>
![classDiagramOverview.PNG](classDiagramOverview.PNG)
