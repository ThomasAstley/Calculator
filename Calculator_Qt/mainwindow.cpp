#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double firstNum, secondNum, result;

void MainWindow::on_additionButton_clicked()
{
    firstNum = ui->txtFirstNum->text().toInt();
    secondNum = ui->txtSecondNum->text().toInt();
    result = firstNum + secondNum;
    ui->txtResult->setText(QString::number(result));
}

void MainWindow::on_subtractionButton_clicked()
{
    firstNum = ui->txtFirstNum->text().toInt();
    secondNum = ui->txtSecondNum->text().toInt();
    result = firstNum - secondNum;
    ui->txtResult->setText(QString::number(result));
}

void MainWindow::on_multiplicationButton_clicked()
{
    firstNum = ui->txtFirstNum->text().toInt();
    secondNum = ui->txtSecondNum->text().toInt();
    result = firstNum * secondNum;
    ui->txtResult->setText(QString::number(result));
}

void MainWindow::on_divisionButton_clicked()
{
    secondNum = ui->txtSecondNum->text().toDouble();

    if (secondNum!=0){
        firstNum = ui->txtFirstNum->text().toDouble();
        result = firstNum / secondNum;
        ui->txtResult->setText(QString::number(result));
    }
    else {
        ui->txtResult->setText(QString("Error: Trying to divide by 0"));
    }
}


QString calculation;

void MainWindow::on_zeroButton_clicked()
{
    calculation.append("0");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_oneButton_clicked()
{
    calculation.append("1");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_twoButton_clicked()
{
    calculation.append("2");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_threeButton_clicked()
{
    calculation.append("3");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_fourButton_clicked()
{
    calculation.append("4");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_fiveButton_clicked()
{
    calculation.append("5");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_sixButton_clicked()
{
    calculation.append("6");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_sevenButton_clicked()
{
    calculation.append("7");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_eightButton_clicked()
{
    calculation.append("8");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_nineButton_clicked()
{
    calculation.append("9");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_pointButton_clicked()
{
    calculation.append(".");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_additionButton_2_clicked()
{
    calculation.append("+");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_subtractionButton_2_clicked()
{
    calculation.append("-");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_multiplicationButton_2_clicked()
{
    calculation.append("*");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_divisionButton_2_clicked()
{
    calculation.append("/");
    ui->txtCalculation->setText(calculation);
}

void MainWindow::on_deleteButton_clicked()
{
    calculation.removeLast();
    ui->txtCalculation->setText(calculation);
}


void MainWindow::on_equalsButton_clicked()
{

}

