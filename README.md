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
Cordinate class : holds the X and Y (unsgined) cordinate value. <br/>
Board class : holds the attributes of a board. (and do not paint anything on itself by itself)<br/>
Snake class : hold the length and color of the snake. (also do not paint anything on itself by itself)<br/>
Fruit class : As name suggests it hold the attribute of a fruit ie color in this context.(type of fruit do not matter)<br/>
MoveManager : This is static class, responsible of the movement of the different entities on the board,here snake and fruit. Also this class is only responsible for calculating the new cordniate of snake and fruit (if its is eaten).<br/>
MoveValidator : a interface<br/>
GameOverValiadator : a concrete class of MoveValidator. and only validate if passed cordinate forms a cycle (condition to stop game).<br/>
Painter : a interface<br/>
SnakePainter : this class is responsible to paint the snake onto the RenderWindow.<br/>
FruitPainter : this class is responsible to paint the fruit onto the RenderWindow.<br/>
GameOverPainter : this class is responsible to paint the game over text onto the RenderWindow. <br/>

Below is the overview of the class diagram (please note that relationship between classes are not defined completely in the below diagram)
![classDiagramOverview.PNG](classDiagramOverview.PNG)
