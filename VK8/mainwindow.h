#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeout();
    void startHandler();
    void stopHandler();
    void switchHandler();

private:
    Ui::MainWindow *ui;

    QTimer *pQTimer;

    int player1Time;   // jäljellä oleva aika
    int player2Time;
    int maxTime;       // valittu kokonaisaika
    int state;         // 0=ei peliä, 1=P1 vuoro, 2=P2 vuoro, 3=peli lopetettu
    int x;             // kulunut aika sekuntteina

    void updateProgressBar();
    void setGameInfoText(QString a, short fontSize);
};

#endif // MAINWINDOW_H
