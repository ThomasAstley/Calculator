/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBasic;
    QAction *actionScientific;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *ansLabel;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *leftBracketButton;
    QPushButton *rightBracketButton;
    QPushButton *sevenButton;
    QPushButton *eightButton;
    QPushButton *nineButton;
    QPushButton *deleteButton;
    QPushButton *clearButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *sixButton;
    QPushButton *multiplicationButton;
    QPushButton *divisionButton;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *additionButton;
    QPushButton *subtractionButton;
    QPushButton *zeroButton;
    QPushButton *pointButton;
    QPushButton *scientificNotationButton;
    QPushButton *ansButton;
    QPushButton *equalsButton;
    QLineEdit *txtExpression;
    QLineEdit *txtAns;
    QMenuBar *menuBar;
    QMenu *menuMode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(356, 343);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(250, 250));
        MainWindow->setIconSize(QSize(20, 20));
        actionBasic = new QAction(MainWindow);
        actionBasic->setObjectName("actionBasic");
        actionScientific = new QAction(MainWindow);
        actionScientific->setObjectName("actionScientific");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        ansLabel = new QLabel(centralwidget);
        ansLabel->setObjectName("ansLabel");
        QFont font;
        font.setPointSize(16);
        ansLabel->setFont(font);

        gridLayout->addWidget(ansLabel, 1, 0, 1, 1);

        leftButton = new QPushButton(centralwidget);
        leftButton->setObjectName("leftButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftButton->sizePolicy().hasHeightForWidth());
        leftButton->setSizePolicy(sizePolicy1);
        leftButton->setMinimumSize(QSize(40, 40));
        QFont font1;
        font1.setPointSize(14);
        leftButton->setFont(font1);
        leftButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(leftButton, 2, 2, 1, 1);

        rightButton = new QPushButton(centralwidget);
        rightButton->setObjectName("rightButton");
        sizePolicy1.setHeightForWidth(rightButton->sizePolicy().hasHeightForWidth());
        rightButton->setSizePolicy(sizePolicy1);
        rightButton->setMinimumSize(QSize(40, 40));
        rightButton->setFont(font1);
        rightButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(rightButton, 2, 3, 1, 1);

        leftBracketButton = new QPushButton(centralwidget);
        leftBracketButton->setObjectName("leftBracketButton");
        sizePolicy1.setHeightForWidth(leftBracketButton->sizePolicy().hasHeightForWidth());
        leftBracketButton->setSizePolicy(sizePolicy1);
        leftBracketButton->setMinimumSize(QSize(40, 40));
        leftBracketButton->setFont(font1);
        leftBracketButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(leftBracketButton, 2, 4, 1, 1);

        rightBracketButton = new QPushButton(centralwidget);
        rightBracketButton->setObjectName("rightBracketButton");
        sizePolicy1.setHeightForWidth(rightBracketButton->sizePolicy().hasHeightForWidth());
        rightBracketButton->setSizePolicy(sizePolicy1);
        rightBracketButton->setMinimumSize(QSize(40, 40));
        rightBracketButton->setFont(font1);
        rightBracketButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(rightBracketButton, 2, 5, 1, 1);

        sevenButton = new QPushButton(centralwidget);
        sevenButton->setObjectName("sevenButton");
        sizePolicy1.setHeightForWidth(sevenButton->sizePolicy().hasHeightForWidth());
        sevenButton->setSizePolicy(sizePolicy1);
        sevenButton->setMinimumSize(QSize(40, 40));
        sevenButton->setFont(font1);
        sevenButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(sevenButton, 3, 1, 1, 1);

        eightButton = new QPushButton(centralwidget);
        eightButton->setObjectName("eightButton");
        sizePolicy1.setHeightForWidth(eightButton->sizePolicy().hasHeightForWidth());
        eightButton->setSizePolicy(sizePolicy1);
        eightButton->setMinimumSize(QSize(40, 40));
        eightButton->setFont(font1);
        eightButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(eightButton, 3, 2, 1, 1);

        nineButton = new QPushButton(centralwidget);
        nineButton->setObjectName("nineButton");
        sizePolicy1.setHeightForWidth(nineButton->sizePolicy().hasHeightForWidth());
        nineButton->setSizePolicy(sizePolicy1);
        nineButton->setMinimumSize(QSize(40, 40));
        nineButton->setFont(font1);
        nineButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(nineButton, 3, 3, 1, 1);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);
        deleteButton->setMinimumSize(QSize(40, 40));
        deleteButton->setFont(font1);
        deleteButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(deleteButton, 3, 4, 1, 1);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        sizePolicy1.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy1);
        clearButton->setMinimumSize(QSize(40, 40));
        clearButton->setFont(font1);
        clearButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(clearButton, 3, 5, 1, 1);

        fourButton = new QPushButton(centralwidget);
        fourButton->setObjectName("fourButton");
        sizePolicy1.setHeightForWidth(fourButton->sizePolicy().hasHeightForWidth());
        fourButton->setSizePolicy(sizePolicy1);
        fourButton->setMinimumSize(QSize(40, 40));
        fourButton->setFont(font1);
        fourButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(fourButton, 4, 1, 1, 1);

        fiveButton = new QPushButton(centralwidget);
        fiveButton->setObjectName("fiveButton");
        sizePolicy1.setHeightForWidth(fiveButton->sizePolicy().hasHeightForWidth());
        fiveButton->setSizePolicy(sizePolicy1);
        fiveButton->setMinimumSize(QSize(40, 40));
        fiveButton->setFont(font1);
        fiveButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(fiveButton, 4, 2, 1, 1);

        sixButton = new QPushButton(centralwidget);
        sixButton->setObjectName("sixButton");
        sizePolicy1.setHeightForWidth(sixButton->sizePolicy().hasHeightForWidth());
        sixButton->setSizePolicy(sizePolicy1);
        sixButton->setMinimumSize(QSize(40, 40));
        sixButton->setFont(font1);
        sixButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(sixButton, 4, 3, 1, 1);

        multiplicationButton = new QPushButton(centralwidget);
        multiplicationButton->setObjectName("multiplicationButton");
        sizePolicy1.setHeightForWidth(multiplicationButton->sizePolicy().hasHeightForWidth());
        multiplicationButton->setSizePolicy(sizePolicy1);
        multiplicationButton->setMinimumSize(QSize(40, 40));
        multiplicationButton->setFont(font1);
        multiplicationButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(multiplicationButton, 4, 4, 1, 1);

        divisionButton = new QPushButton(centralwidget);
        divisionButton->setObjectName("divisionButton");
        sizePolicy1.setHeightForWidth(divisionButton->sizePolicy().hasHeightForWidth());
        divisionButton->setSizePolicy(sizePolicy1);
        divisionButton->setMinimumSize(QSize(40, 40));
        divisionButton->setFont(font1);
        divisionButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(divisionButton, 4, 5, 1, 1);

        oneButton = new QPushButton(centralwidget);
        oneButton->setObjectName("oneButton");
        sizePolicy1.setHeightForWidth(oneButton->sizePolicy().hasHeightForWidth());
        oneButton->setSizePolicy(sizePolicy1);
        oneButton->setMinimumSize(QSize(40, 40));
        oneButton->setFont(font1);
        oneButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(oneButton, 5, 1, 1, 1);

        twoButton = new QPushButton(centralwidget);
        twoButton->setObjectName("twoButton");
        sizePolicy1.setHeightForWidth(twoButton->sizePolicy().hasHeightForWidth());
        twoButton->setSizePolicy(sizePolicy1);
        twoButton->setMinimumSize(QSize(40, 40));
        twoButton->setFont(font1);
        twoButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(twoButton, 5, 2, 1, 1);

        threeButton = new QPushButton(centralwidget);
        threeButton->setObjectName("threeButton");
        sizePolicy1.setHeightForWidth(threeButton->sizePolicy().hasHeightForWidth());
        threeButton->setSizePolicy(sizePolicy1);
        threeButton->setMinimumSize(QSize(40, 40));
        threeButton->setFont(font1);
        threeButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(threeButton, 5, 3, 1, 1);

        additionButton = new QPushButton(centralwidget);
        additionButton->setObjectName("additionButton");
        additionButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(additionButton->sizePolicy().hasHeightForWidth());
        additionButton->setSizePolicy(sizePolicy1);
        additionButton->setMinimumSize(QSize(40, 40));
        additionButton->setFont(font1);
        additionButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(additionButton, 5, 4, 1, 1);

        subtractionButton = new QPushButton(centralwidget);
        subtractionButton->setObjectName("subtractionButton");
        sizePolicy1.setHeightForWidth(subtractionButton->sizePolicy().hasHeightForWidth());
        subtractionButton->setSizePolicy(sizePolicy1);
        subtractionButton->setMinimumSize(QSize(40, 40));
        subtractionButton->setFont(font1);
        subtractionButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(subtractionButton, 5, 5, 1, 1);

        zeroButton = new QPushButton(centralwidget);
        zeroButton->setObjectName("zeroButton");
        sizePolicy1.setHeightForWidth(zeroButton->sizePolicy().hasHeightForWidth());
        zeroButton->setSizePolicy(sizePolicy1);
        zeroButton->setMinimumSize(QSize(40, 40));
        zeroButton->setFont(font1);
        zeroButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(zeroButton, 6, 1, 1, 1);

        pointButton = new QPushButton(centralwidget);
        pointButton->setObjectName("pointButton");
        sizePolicy1.setHeightForWidth(pointButton->sizePolicy().hasHeightForWidth());
        pointButton->setSizePolicy(sizePolicy1);
        pointButton->setMinimumSize(QSize(40, 40));
        pointButton->setFont(font1);
        pointButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pointButton, 6, 2, 1, 1);

        scientificNotationButton = new QPushButton(centralwidget);
        scientificNotationButton->setObjectName("scientificNotationButton");
        sizePolicy1.setHeightForWidth(scientificNotationButton->sizePolicy().hasHeightForWidth());
        scientificNotationButton->setSizePolicy(sizePolicy1);
        scientificNotationButton->setMinimumSize(QSize(40, 40));
        scientificNotationButton->setFont(font1);
        scientificNotationButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(scientificNotationButton, 6, 3, 1, 1);

        ansButton = new QPushButton(centralwidget);
        ansButton->setObjectName("ansButton");
        sizePolicy1.setHeightForWidth(ansButton->sizePolicy().hasHeightForWidth());
        ansButton->setSizePolicy(sizePolicy1);
        ansButton->setMinimumSize(QSize(40, 40));
        ansButton->setFont(font1);
        ansButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(ansButton, 6, 4, 1, 1);

        equalsButton = new QPushButton(centralwidget);
        equalsButton->setObjectName("equalsButton");
        sizePolicy1.setHeightForWidth(equalsButton->sizePolicy().hasHeightForWidth());
        equalsButton->setSizePolicy(sizePolicy1);
        equalsButton->setMinimumSize(QSize(40, 40));
        equalsButton->setFont(font1);
        equalsButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(equalsButton, 6, 5, 1, 1);

        txtExpression = new QLineEdit(centralwidget);
        txtExpression->setObjectName("txtExpression");
        txtExpression->setFont(font);

        gridLayout->addWidget(txtExpression, 0, 0, 1, 6);

        txtAns = new QLineEdit(centralwidget);
        txtAns->setObjectName("txtAns");
        txtAns->setFont(font);
        txtAns->setReadOnly(true);

        gridLayout->addWidget(txtAns, 1, 1, 1, 5);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 356, 17));
        menuMode = new QMenu(menuBar);
        menuMode->setObjectName("menuMode");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMode->menuAction());
        menuMode->addAction(actionBasic);
        menuMode->addAction(actionScientific);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionBasic->setText(QCoreApplication::translate("MainWindow", "Basic", nullptr));
        actionScientific->setText(QCoreApplication::translate("MainWindow", "Scientific", nullptr));
        ansLabel->setText(QCoreApplication::translate("MainWindow", "Ans:", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        leftBracketButton->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        rightBracketButton->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        sevenButton->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        eightButton->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        nineButton->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        fourButton->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        fiveButton->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        sixButton->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        multiplicationButton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        divisionButton->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        oneButton->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        twoButton->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        threeButton->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        additionButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subtractionButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        zeroButton->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pointButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        scientificNotationButton->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        ansButton->setText(QCoreApplication::translate("MainWindow", "Ans", nullptr));
        equalsButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        menuMode->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
