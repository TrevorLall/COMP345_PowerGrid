How to create a map file:

1. open a text file
2. write the name of the head city followed by ":"
3. After the ":" write the node cites that are connected the head and seperate them by "-"
for example: head:nodeCity1-nodeCity2-nodeCity3
4. save the text file.

Loading Maps:
Maps are loaded using the MapLoader Class

1. Create fstream object and open then MAP text file 
2. Create a MapLoader object
3. Use the loadMap function to create a graph which is stored as a Map object
4. Using the Map classes printMap function the each city will be display with it the cities connected to it.

Creating a Player:
The Player class is used to create players for the game

1. Declare an object of Player class
2. When initializing the player object the name,color, player num and elektro(money) must be set.


Resources:
Resources such as coal,oil,garbage and uranium are objects that contain a pointer to a player object so
they can be owned by the player.

Houses:
Houses contain a pointer to a player object so they can be owned by a player.
Houses can also be placed on the map through the city class since the city class has a pointer to a house object.


Summary Cards:
The summary card is aobject that provides the player with information about the 5 phases of a turn.

Deck:
The deck class is used to create the 42 power plant cards and step3 card.

1. Declare an object of Deck class.
2. For powerplants set the card number,card name, resource name,and the number of resources requires in the constructor.
   For the stpe 3 card set the card name to step 3 and the int fields to 0 and the resource name to blank.