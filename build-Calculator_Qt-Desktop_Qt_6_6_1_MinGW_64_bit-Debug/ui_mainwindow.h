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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *firstNumLabel;
    QLabel *secondNumLabel;
    QLineEdit *txtFirstNum;
    QLineEdit *txtSecondNum;
    QPushButton *additionButton;
    QLabel *operatorLabel;
    QPushButton *subtractionButton;
    QPushButton *multiplicationButton;
    QPushButton *divisionButton;
    QLineEdit *txtResult;
    QLabel *resultLabel;
    QLineEdit *txtCalculation;
    QLineEdit *txtFirstNum_3;
    QLabel *ansLabel;
    QPushButton *multiplicationButton_2;
    QPushButton *additionButton_2;
    QPushButton *subtractionButton_2;
    QPushButton *divisionButton_2;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *sixButton;
    QPushButton *sevenButton;
    QPushButton *eightButton;
    QPushButton *nineButton;
    QPushButton *zeroButton;
    QPushButton *pointButton;
    QPushButton *threeButton;
    QPushButton *deleteButton;
    QPushButton *equalsButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(489, 245);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        firstNumLabel = new QLabel(centralwidget);
        firstNumLabel->setObjectName("firstNumLabel");
        firstNumLabel->setGeometry(QRect(20, 10, 71, 21));
        secondNumLabel = new QLabel(centralwidget);
        secondNumLabel->setObjectName("secondNumLabel");
        secondNumLabel->setGeometry(QRect(20, 70, 71, 21));
        txtFirstNum = new QLineEdit(centralwidget);
        txtFirstNum->setObjectName("txtFirstNum");
        txtFirstNum->setGeometry(QRect(100, 10, 111, 20));
        txtSecondNum = new QLineEdit(centralwidget);
        txtSecondNum->setObjectName("txtSecondNum");
        txtSecondNum->setGeometry(QRect(100, 70, 111, 20));
        additionButton = new QPushButton(centralwidget);
        additionButton->setObjectName("additionButton");
        additionButton->setGeometry(QRect(100, 40, 21, 18));
        operatorLabel = new QLabel(centralwidget);
        operatorLabel->setObjectName("operatorLabel");
        operatorLabel->setGeometry(QRect(20, 40, 71, 21));
        subtractionButton = new QPushButton(centralwidget);
        subtractionButton->setObjectName("subtractionButton");
        subtractionButton->setGeometry(QRect(130, 40, 21, 18));
        multiplicationButton = new QPushButton(centralwidget);
        multiplicationButton->setObjectName("multiplicationButton");
        multiplicationButton->setGeometry(QRect(160, 40, 21, 18));
        divisionButton = new QPushButton(centralwidget);
        divisionButton->setObjectName("divisionButton");
        divisionButton->setGeometry(QRect(190, 40, 21, 18));
        txtResult = new QLineEdit(centralwidget);
        txtResult->setObjectName("txtResult");
        txtResult->setGeometry(QRect(100, 130, 111, 20));
        txtResult->setReadOnly(true);
        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setGeometry(QRect(20, 130, 71, 21));
        txtCalculation = new QLineEdit(centralwidget);
        txtCalculation->setObjectName("txtCalculation");
        txtCalculation->setGeometry(QRect(240, 10, 231, 21));
        txtFirstNum_3 = new QLineEdit(centralwidget);
        txtFirstNum_3->setObjectName("txtFirstNum_3");
        txtFirstNum_3->setGeometry(QRect(360, 30, 111, 20));
        ansLabel = new QLabel(centralwidget);
        ansLabel->setObjectName("ansLabel");
        ansLabel->setGeometry(QRect(330, 30, 21, 21));
        multiplicationButton_2 = new QPushButton(centralwidget);
        multiplicationButton_2->setObjectName("multiplicationButton_2");
        multiplicationButton_2->setGeometry(QRect(420, 90, 20, 20));
        additionButton_2 = new QPushButton(centralwidget);
        additionButton_2->setObjectName("additionButton_2");
        additionButton_2->setEnabled(true);
        additionButton_2->setGeometry(QRect(420, 120, 20, 20));
        subtractionButton_2 = new QPushButton(centralwidget);
        subtractionButton_2->setObjectName("subtractionButton_2");
        subtractionButton_2->setGeometry(QRect(450, 120, 20, 20));
        divisionButton_2 = new QPushButton(centralwidget);
        divisionButton_2->setObjectName("divisionButton_2");
        divisionButton_2->setGeometry(QRect(450, 90, 20, 20));
        oneButton = new QPushButton(centralwidget);
        oneButton->setObjectName("oneButton");
        oneButton->setGeometry(QRect(330, 120, 20, 20));
        twoButton = new QPushButton(centralwidget);
        twoButton->setObjectName("twoButton");
        twoButton->setGeometry(QRect(360, 120, 20, 20));
        fourButton = new QPushButton(centralwidget);
        fourButton->setObjectName("fourButton");
        fourButton->setGeometry(QRect(330, 90, 20, 20));
        fiveButton = new QPushButton(centralwidget);
        fiveButton->setObjectName("fiveButton");
        fiveButton->setGeometry(QRect(360, 90, 20, 20));
        sixButton = new QPushButton(centralwidget);
        sixButton->setObjectName("sixButton");
        sixButton->setGeometry(QRect(390, 90, 20, 20));
        sevenButton = new QPushButton(centralwidget);
        sevenButton->setObjectName("sevenButton");
        sevenButton->setGeometry(QRect(330, 60, 20, 20));
        eightButton = new QPushButton(centralwidget);
        eightButton->setObjectName("eightButton");
        eightButton->setGeometry(QRect(360, 60, 20, 20));
        nineButton = new QPushButton(centralwidget);
        nineButton->setObjectName("nineButton");
        nineButton->setGeometry(QRect(390, 60, 20, 20));
        zeroButton = new QPushButton(centralwidget);
        zeroButton->setObjectName("zeroButton");
        zeroButton->setGeometry(QRect(330, 150, 20, 20));
        pointButton = new QPushButton(centralwidget);
        pointButton->setObjectName("pointButton");
        pointButton->setGeometry(QRect(360, 150, 20, 20));
        threeButton = new QPushButton(centralwidget);
        threeButton->setObjectName("threeButton");
        threeButton->setGeometry(QRect(390, 120, 20, 20));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(420, 60, 20, 20));
        equalsButton = new QPushButton(centralwidget);
        equalsButton->setObjectName("equalsButton");
        equalsButton->setGeometry(QRect(450, 150, 20, 20));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        firstNumLabel->setText(QCoreApplication::translate("MainWindow", "First Number:", nullptr));
        secondNumLabel->setText(QCoreApplication::translate("MainWindow", "Second Number:", nullptr));
        additionButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        operatorLabel->setText(QCoreApplication::translate("MainWindow", "Operator", nullptr));
        subtractionButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        multiplicationButton->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        divisionButton->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "Result:", nullptr));
        ansLabel->setText(QCoreApplication::translate("MainWindow", "Ans:", nullptr));
        multiplicationButton_2->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        additionButton_2->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        subtractionButton_2->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        divisionButton_2->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        oneButton->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        twoButton->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        fourButton->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        fiveButton->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        sixButton->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        sevenButton->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        eightButton->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        nineButton->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        zeroButton->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pointButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        threeButton->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        equalsButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
