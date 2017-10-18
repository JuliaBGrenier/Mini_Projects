#include "player2.h"

using namespace std;

Player2::Player2(QWidget *parent, QString p1_word) : QDialog(parent)
{
    word = p1_word.toLower();
    word_hidden = transformWord_(p1_word);
    guesses = "Guesses :";

    layout = new QVBoxLayout();
    layout->setSpacing(15);
    player2 = new QLabel("Player2");
    player2->setAlignment(Qt::AlignCenter);
    mainText = new QLabel("Try to guess the word :");
    mainText->setAlignment(Qt::AlignCenter);
    show_word = new QLabel(addSpace(word_hidden));
    show_word->setAlignment(Qt::AlignCenter);
    show_guesses = new QLabel(guesses);
    input_guess = new QLineEdit();
    goodOrWrong = new QLabel();
    try_it = new QPushButton("Try");

    layout->addWidget(player2);
    layout->addWidget(mainText);
    layout->addWidget(show_word);
    layout->addWidget(show_guesses);
    layout->addWidget(input_guess);
    layout->addWidget(goodOrWrong);
    layout->addWidget(try_it);
    setLayout(layout);

    setMinimumWidth(500);

    connect(try_it, SIGNAL(clicked()), this, SLOT(checkInput()) );
}

QString Player2::addSpace(QString word1) const {
    QString newWord(word1);
    for (int i=1; i<(word1.size()*2); i++) {
        newWord.insert(i, " ");
        i++;
    }
    return newWord;
}

QString Player2::transformWord_(QString word1) const{
    QString newWord;
    for (int i=1; i<=word1.size(); i++) {
        newWord += "_";
    }
    return newWord;
}

bool Player2::makeModification(QChar letter) {
    QString copy(word_hidden);
    for (int i=0; i<=(word.size()+1); i++) {
        if (word[i] == letter) {
            word_hidden[i] = letter;
        }
    }
    if (word_hidden != copy) {
        show_word->setText(addSpace(word_hidden));
        return true;
    } else
        return false;
}


void Player2::checkInput() {
    if (input_guess->text() != "") {
        if (input_guess->text().size() >= 2) {
            if (input_guess->text() == word) {
                QMessageBox::information(this, "Good answer", "Good job ! You got the word ! :D");
                close();
            } else {
                QMessageBox::information(this, "Wrong answer", "Ohh no... You didn't get the word ! :(");
            }
        } else if (input_guess->text().size() == 1){
            if (makeModification(input_guess->text()[0])){
                goodOrWrong->setText("Good letter ! Good job ! There is a " + input_guess->text()[0] + " in the word !");
                guesses.insert(guesses.size(), " "+input_guess->text()[0]);
                show_guesses->setText(guesses);
            } else {
                goodOrWrong->setText("Wrong letter ! There is no " + input_guess->text()[0] + " in the word !");
                guesses.insert(guesses.size(), " "+input_guess->text()[0]);
                show_guesses->setText(guesses);
            }
            if (word_hidden == word) {
                QMessageBox::information(this, "Good answer", "Good job ! You got the word ! :D");
                close();
            }
        }
        input_guess->setText("");
    }
}
