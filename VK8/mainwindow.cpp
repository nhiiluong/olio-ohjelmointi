#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pQTimer = new QTimer(this);

    player1Time = 0;
    player2Time = 0;
    maxTime     = 0;
    state       = 0;
    x           = 0;

    // Progressbarit prosentteina
    ui->progressBar->setRange(0, 100);
    ui->progressBar_2->setRange(0, 100);
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);

    connect(pQTimer, SIGNAL(timeout()), this, SLOT(timeout()));

    connect(ui->Startgame,     SIGNAL(clicked(bool)), this, SLOT(startHandler()));
    connect(ui->Stopgame,      SIGNAL(clicked(bool)), this, SLOT(stopHandler()));
    connect(ui->Switchplayer1, SIGNAL(clicked(bool)), this, SLOT(switchHandler()));
    connect(ui->Switchplayer2, SIGNAL(clicked(bool)), this, SLOT(switchHandler()));
    connect(ui->time120s,      SIGNAL(clicked(bool)), this, SLOT(startHandler()));
    connect(ui->time5min,      SIGNAL(clicked(bool)), this, SLOT(startHandler()));

    setGameInfoText("Select playtime and press start game!", 16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGameInfoText(QString a, short fontSize)
{
    ui->textlabel->setText(a);
    QFont font = ui->textlabel->font();
    font.setPointSize(fontSize);
    ui->textlabel->setFont(font);
}

void MainWindow::updateProgressBar()
{
    if (maxTime <= 0) {
        ui->progressBar->setValue(0);
        ui->progressBar_2->setValue(0);
        return;
    }

    int p1 = (player1Time * 100) / maxTime;
    int p2 = (player2Time * 100) / maxTime;

    if (p1 < 0) p1 = 0;
    if (p2 < 0) p2 = 0;

    ui->progressBar->setValue(p1);
    ui->progressBar_2->setValue(p2);
}

void MainWindow::startHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString name = button->objectName();
    qDebug() << "Button name:" << name;

    if (name == "time120s") {
        maxTime     = 120;
        player1Time = maxTime;
        player2Time = maxTime;
        updateProgressBar();
        setGameInfoText("Ready to play!", 16);
    }
    else if (name == "time5min") {
        maxTime     = 300;
        player1Time = maxTime;
        player2Time = maxTime;
        updateProgressBar();
        setGameInfoText("Ready to play!", 16);
    }
    else if (name == "Startgame") {
        if (maxTime == 0) {
            setGameInfoText("Select time first!", 16);
            return;
        }
        state = 1; // Player 1 aloittaa
        pQTimer->start(1000);
        x = 0;
        setGameInfoText("Game ongoing: Player 1 turn", 16);
    }
}

void MainWindow::stopHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString name = button->objectName();
    qDebug() << "Button name:" << name;

    if (name == "Stopgame") {
        pQTimer->stop();
        state = 3;

        if (player1Time > player2Time)
            setGameInfoText("Player 1 WON!", 16);
        else if (player2Time > player1Time)
            setGameInfoText("Player 2 WON!", 16);
        else
            setGameInfoText("Draw! Start new game.", 16);
    }
}

void MainWindow::switchHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString name = button->objectName();
    qDebug() << "Button name:" << name;

    if (name == "Switchplayer1") {
        state = 2; // pelaaja 2 vuoro
        setGameInfoText("Game ongoing: Player 2 turn", 16);
    }
    else if (name == "Switchplayer2") {
        state = 1; // pelaaja 1 vuoro
        setGameInfoText("Game ongoing: Player 1 turn", 16);
    }
}

void MainWindow::timeout()
{
    x++;
    qDebug() << "Aikaa kulunut" << x << "sekuntia";

    if (state == 1) {
        player1Time--;
        qDebug() << "Player 1 aikaa jäljellä" << player1Time;
    }
    else if (state == 2) {
        player2Time--;
        qDebug() << "Player 2 aikaa jäljellä" << player2Time;
    } else {
        return;
    }

    updateProgressBar();

    if (player1Time <= 0) {
        pQTimer->stop();
        setGameInfoText("Player 2 WON!", 16);
    }
    else if (player2Time <= 0) {
        pQTimer->stop();
        setGameInfoText("Player 1 WON!", 16);
    }
}
