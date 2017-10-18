#include "player1.h"

Player1::Player1(QWidget *parent) : QWidget(parent)
{
    main_layout = new QVBoxLayout();
    formLayout = new QFormLayout();
    player1 = new QLabel("Player1");
    player1->setAlignment(Qt::AlignCenter);
    input_word = new QLineEdit();
    ok = new QPushButton("Ok");

    formLayout->addRow("Input a word :", input_word);

    main_layout->addWidget(player1);
    main_layout->addLayout(formLayout);
    main_layout->addWidget(ok);

    main_layout->setMargin(30);
    main_layout->setSpacing(15);

    setLayout(main_layout);


    connect(ok, SIGNAL(clicked()), this, SLOT(startPlayer2Turn()) );
}

void Player1::startPlayer2Turn() {
    if (input_word->text() != "") {
        word = input_word->text();
        p2 = new Player2(this, word);
        hide();
        p2->exec();
        input_word->setText("");
        show();
    }
}
