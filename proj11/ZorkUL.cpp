#include <iostream>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char *argv[]) {
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

    a = new Room("[Hallway]"
                 "   This Hallway is a long dark stretch of about 50 yards in a spaceship many of kilometers above earths surface there is 6 rooms along this hallway with 3 doors on either side,"
                 "   if you look down you can see a welcome letter introducing you to the crew and also welcoming you to our spaceship"
                 " there is a screwdriver that might come in useful :) ");
        a->addItem(new Item("Welcome letter", 1, 11));
        a->addItem(new Item("Screwdriver", 2, 22));
    b = new Room("[Command Centre]"
                 "   here we can see where all our assignments are talked about and where we will be going on our adventures"
                 "   the book about life can be found on the desk and it may explain alot of your questions"
                 "   there is also a boyzone poster simply because who doesnt like boyzone");
        b->addItem(new Item("Book About Life", 3, 33));
        b->addItem(new Item("Boyzone Poster", 4, 44));
    c = new Room("[Navigation Centre]"
                 "   this room is one of the most important rooms on our spaceship as this is where the driver of the ship works"
                 "   he will steer us in the right direction"
                 "   if you feel like helping out maybe pick up the compass and pencil to assist on the journey");
        c->addItem(new Item("Compass", 5, 55));
        c->addItem(new Item("Pencil", 6, 66));
    d = new Room("[Med-Bay]"
                 "   as you know we are up on this spaceship due to the outbreak of covid-19 and incase of an emergencey infection "
                 "   ONLY USE THE SRYNGE OR COVID-19 VACCINE IN AN EMERGENCEY ");
        d->addItem(new Item("Covid19 Vaccine", 7, 77));
        d->addItem(new Item("Srynge", 8, 88));
    e = new Room("[Zero-Gravity Room]"
                 "    They say the zero-gravity room is the best place on the ship to relax and chill out"
                 "    what ever you do make sure to put on your oxygen mask within 30 seconds of entering the room"
                 "    and why not throw on the gravity suit to optamise your expierence");
        e->addItem(new Item("Gravity suit", 9, 99));
        e->addItem(new Item("Oxygen Mask", 1, 11));
    f = new Room("[Restrooms]"
                 "the restrooms are very dirty because the cleaning lady got ill so make sure to try keep it tidy"
                 "you may also find something you would be better off not finding.....");
        f->addItem(new Item("Plunger", 2, 22));
        f->addItem(new Item("Secret note about commander", 3, 33));
    g = new Room("[Sleeping Quarter]"
                 "  the sleeping quaters are where you sleep, reset the body for the next long and tiresome day"
                 "  if you look on your drawer you will witness flashbacks of the goodtimes you had with your family before the outbreak");
        g->addItem(new Item("Letter from home", 4, 44));
        g->addItem(new Item("Picture of family", 5, 55));
    h = new Room("[Plant/Growing room]"
                 "   this is the room where we grow all our food that keeps us alive if you ever feel hungry feel free to take a spud :0"
                 "    and DO NOT PLAY WITH THE FERTILIZER.....");
        h->addItem(new Item("Fertilizer", 6, 66));
        h->addItem(new Item("Potato", 7, 77));
    i = new Room("[Maintanance room]"
                 "   ohh look billy is in the maintanance room, maybe you should go and say Hi"
                 "   or maybe not billy is knowing for his temper and there are roumers he even has a gun !!!"
                 "   other than that he is handy to have around as he is a master of all trades");
        i->addItem(new Item("Battery opperated Drill", 8, 88));
        i->addItem(new Item("Vintage Gun", 9, 99));
    j = new Room("[exit-to-outerspace]"
                 "   if you ever wish to leave the space ship this is how you exit make sure you are geared up"
                 "   because when you leave you will not be able to enter the room again"
                 "   your jetpack will allow you to fly through outerspace and try get back to earth!!!");
        j->addItem(new Item("space helmet", 1, 11));
        j->addItem(new Item("jetpack", 2, 22));
    k = new Room("[Space-suit-room]"
                 "   if you are feeling ready to leave make sure to pick up your spacesuit"
                 "   there is also a sergical mask for your return to planet earth.");
        k->addItem(new Item("Space-suit", 3, 33));
        k->addItem(new Item("sergical mask", 4, 44));
    l = new Room("[Sceret-room]");
        l->addItem(new Item("code to exit to outerspace *8490*", 5, 55));
        l->addItem(new Item("notepad", 6, 66));
    m = new Room("[Enchantment room]"
                 "   you might be able to upgrade some of the items that you picked up throught the spaceship"
                 "   but first the items in the enchantment room will help you work your spells!");
        m->addItem(new Item("Enchantment Book", 7, 77));
        m->addItem(new Item("Weird yellow liquid", 8, 88));


//             (N, E, S, W)
    a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, l, i);
	e->setExits(NULL, NULL, NULL, d);
    f->setExits(m, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, k, NULL, NULL);
    k->setExits(NULL, NULL, NULL, j);
    l->setExits(d, NULL, NULL, NULL);
    m->setExits(NULL, k, f, j);


        rooms.push_back(*a);
        rooms.push_back(*b);
        rooms.push_back(*c);
        rooms.push_back(*d);
        rooms.push_back(*e);
        rooms.push_back(*f);
        rooms.push_back(*g);
        rooms.push_back(*h);
        rooms.push_back(*i);
        rooms.push_back(*j);
        rooms.push_back(*k);
        rooms.push_back(*l);
        rooms.push_back(*m);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "welcome to spaceship 3, the final spaceship to leave earth before the outbreak of covid 19."
            "you should count yourself lucky!!!"
            "your mission is to try to create a cure for the virus before it takes over the spaceship"
            "there is some people on the spaceship that dont want to cooperate with the work so watch out"
            "try and save the world!!!"
            "best of luck "<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "   [j]--[m]--[k]    " << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "        [l]        " << endl;

        }

	else if (commandWord.compare("go") == 0)
		goRoom(command);
    else if (commandWord.compare("teleport") == 0)
               teleport();

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}
string ZorkUL::teleport() {
    currentRoom = &rooms.at((int) rand() % rooms.size());
        cout << currentRoom->longDescription() << endl;
        return "Teleportation Successfull";
}
void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
