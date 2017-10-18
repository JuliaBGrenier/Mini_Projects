#ifndef PLAYER2_H
#define PLAYER2_H

#include <QWidget>
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QString>
#include <QChar>

#include <iostream>

class Player2 : public QDialog
{
    Q_OBJECT
public:
    Player2(QWidget *parent, QString p1_word);
    QString addSpace(QString word1) const;
    QString transformWord_(QString word1) const;
    bool makeModification(QChar letter);


signals:

public slots:
    void checkInput();

private:
    QVBoxLayout *layout;
    QLabel *player2;
    QLabel *mainText;
    QLabel *show_word;
    QLabel *show_guesses;
    QLineEdit *input_guess;
    QLabel *goodOrWrong;
    QPushButton *try_it;

    QString word;
    QString word_hidden;
    QString guesses;
};

#endif // PLAYER2_H
