#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setText(
            " Welcome to spaceship 3 this is the third and final spaceship to leave eath. Your objective is to research a covid 19 vaccine"
            " The package is hidden somewhere in the house."
            " When your research is complete, exit the spaceship."
            " Good Luck."
            "'info' for help");
}

MainWindow::~MainWindow()
{
    createRooms();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    go("north");
}


void MainWindow::on_pushButton_2_clicked()
{
    go("east");
}


void MainWindow::on_pushButton_3_clicked()
{
    go("south");
}


void MainWindow::on_pushButton_4_clicked()
{
    go("west");
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->setText(
             "..............Spaceship 3...............\n"
             " \n"
             "   [j]--[m]--[k]\n"
             "         |\n"
             "         |\n"
             "[h] --- [f] --- [g] \n"
             "         |\n"
             "         |\n"
             "[c] --- [a] --- [b]\n"
             "         |\n"
             "         |\n"
             "[i] --- [d] --- [e]\n"
             "         |\n"
             "         |\n"
             "        [l] \n"
);
}

void MainWindow::createRooms()  {
    Room *a, *b, *c, *d, *e, *e1, *f, *g, *h, *i, *j, *k, *l, *m,;

   //Downstairs
    a = new Room(" Hallway."
                 " This is a long hallway with a narrow structure, "
                 " there is rooms on each end of the hall."
                 " ."
                 " you have rooms north south east and west.");
    b = new Room("Command center."
                 " here you can see how the spaceship is run "
                 " you can meet the commander"
                 " he is a very sceretive man");
    c = new Room("navigation center"
                 " This room is where the the workers drive the spaceship "
                 " this is a relaxed room where you can chat with the workers "
                 " this room is one of the most important rooms on our spaceship as this is where the driver of the ship works"
                 " if you feel like helping out maybe pick up the compass and pencil to assist on the journey ."
                 " Nothing else here is of any use.");
        c->addItem(new Item("compass", 1, 22));
        c->addItem(new Item("pencil", 3, 33));
        c->addItem(new Item("boyzone poster", 3, 33));
    d = new Room("med-bay."
                 " as you know we are up on this spaceship due to the outbreak of covid-19 and incase of an emergencey infection "
                 " ONLY USE THE SRYNGE OR COVID-19 VACCINE IN AN EMERGENCEY"
                 " there is one person in isolation here.");
    e = new Room("Zero-Gravity Room."
                 " They say the zero-gravity room is the best place on the ship to relax and chill out"
                 " this room can be very important."
                 " zero gravity seems to stop covid spread."
                 " this will help in your research,"
                 " if used correctly this is a huge advancement in your research."
                 " dont be afraid to explore."
                 " and dont forget to relax");
        e->addItem(new Item("gravity suit", 1, 10));
    f = new Room("Restrooms."
                 " this is where you go when you need to go toilet."
                 " the restrooms are very dirty because the cleaning lady got ill so make sure to try keep it tidy.");
        f->addItem(new Item("Secret note about commander", 4, 33));
    g = new Room("Sleeping Quarter."
                 " the sleeping quaters are where you sleep, reset the body for the next long and tiresome day."
                 " if you look on your drawer you will witness flashbacks of the goodtimes you had with your family before the outbreak");
        g->addItem(new Item("Picture of family", 3, 33));
    h = new Room("Plant/Growing room."
                 " this is the room where we grow all our food that keeps us alive if you ever feel hungry feel free to take a spud."
                 " and DO NOT PLAY WITH THE FERTILIZER....."
                 " whats in this room might be useful."
                 " but dangerous");
        h->addItem(new Item("fertilizer", 3, 33));
        h->addItem(new Item("clay", 3, 33));
        h->addItem(new Item("hose", 3, 33));
    i = new Room("Maintanance room."
                 " ohh look billy is in the maintanance room, maybe you should go and say Hi."
                 " or maybe not billy is knowing for his temper and there are roumers he even has a gun !!!");
   j = new Room("exit-to-outerspace."
                 " if you ever wish to leave the space ship this is how you exit make sure you are geared up."
                 " because when you leave you will not be able to enter the room again.");
    k = new Room("Space-suit-room."
                 " if you are feeling ready to leave make sure to pick up your spacesuit."
                 " there is also a sergical mask for your return to planet earth.");
    l = new Room("Sceret-room."
                 " unknown");
    m = new Room("Enchantment room.");

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
void MainWindow::play() {
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

void MainWindow::printWelcome() {
    cout << "Welcome to spaceship 3 the third and final spaceship to leave earth:"<< endl;
    cout << "you have left due to covid 19."<< endl;
    cout << "you are one of the lucky ones to be up in space"<< endl;
    cout << "your mission is to research covid 19."<< endl;
    cout << "and then you should be able to make a cure."<< endl;
    cout << "make sure you dont get covid."<< endl;
    cout << "Good Luck"<< endl;
    cout << "'info' for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool MainWindow::processCommand(Command command) {
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
void MainWindow::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

string MainWindow::teleport() {
    currentRoom = &rooms.at((int) rand() % rooms.size());
        cout << currentRoom->longDescription() << endl;
        return "";
}

void MainWindow::goRoom(Command command) {
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

string MainWindow::go(string direction) {
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

void MainWindow::on_pushButton_7_clicked()
{
        ui->textBrowser->setText("teleport");
    }


void MainWindow::on_pushButton_6_clicked()
{
    ui->textBrowser->setText("take");
}



