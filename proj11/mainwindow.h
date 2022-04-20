mainwindow.cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <string>
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Character.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Character;
    friend class Room;
    friend class ZorkUL;

public:
    explicit MainWindow(QWidget parent = nullptr);
    ~MainWindow();
    void play();
    string go(string direction);
    void teleport();
    //Character:: reduceEnergy();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindowui;
    Parser parser;
    Room *currentRoom;
    vector<Room> rooms;
    void createRooms();
    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();
};
#endif // MAINWINDOW_H
