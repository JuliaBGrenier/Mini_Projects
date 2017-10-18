#ifndef PLAYER1_H
#define PLAYER1_H

#include "player2.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

class Player1 : public QWidget
{
    Q_OBJECT
public:
    explicit Player1(QWidget *parent = nullptr);

signals:

public slots:
    void startPlayer2Turn();

private:
    QVBoxLayout *main_layout;
    QFormLayout *formLayout;
    QLabel *player1;
    QLineEdit *input_word;
    QPushButton *ok;

    Player2 *p2;

    QString word;
};

#endif // PLAYER1_H
