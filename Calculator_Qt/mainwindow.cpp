#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
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


QString expression;

void MainWindow::on_zeroButton_clicked()
{
    expression.append("0");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_oneButton_clicked()
{
    expression.append("1");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_twoButton_clicked()
{
    expression.append("2");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_threeButton_clicked()
{
    expression.append("3");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_fourButton_clicked()
{
    expression.append("4");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_fiveButton_clicked()
{
    expression.append("5");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_sixButton_clicked()
{
    expression.append("6");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_sevenButton_clicked()
{
    expression.append("7");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_eightButton_clicked()
{
    expression.append("8");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_nineButton_clicked()
{
    expression.append("9");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_pointButton_clicked()
{
    expression.append(".");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_additionButton_2_clicked()
{
    expression.append("+");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_subtractionButton_2_clicked()
{
    expression.append("-");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_multiplicationButton_2_clicked()
{
    expression.append("*");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_divisionButton_2_clicked()
{
    expression.append("/");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_deleteButton_clicked()
{
    expression.removeLast();
    ui->txtExpression->setText(expression);
}


void MainWindow::on_equalsButton_clicked()
{
    string expression_string = expression.toStdString();
    char c;
    bool all_division_complete = false;
    bool all_multiplication_complete = false;
    bool all_addition_complete = false;
    bool all_subtraction_complete = false;

    while (!all_division_complete){
        int expression_length = expression_string.length();
        int previous_operator_position = -1;
        int division_position;
        int next_operator_position = expression_length;
        bool division_found = false;

        for(int i=0; i < expression_length; i++) {
            c = expression_string.at(i);
            if ((c == '*' || c == '-' || c == '+' ) && !division_found) {
                previous_operator_position = i;
            }
            else if ((c == '/') && !division_found){
                division_found = true;
                division_position = i;
            }
            else if ((c == '/' || c == '*' || c == '-' || c == '+' ) && division_found){
                next_operator_position = i;
                break;
            }
            else if ((i == expression_length - 1) && !division_found){
                all_division_complete = true;
            }
        }
        if (division_found && !all_division_complete){
            string first_number_string;
            string second_number_string;
            for(int i = previous_operator_position + 1; i < division_position; i++){
                first_number_string += expression_string.at(i);
            }
            for(int i = division_position + 1; i < next_operator_position; i++){
                second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) / stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }
    }

    while (!all_multiplication_complete){
        int expression_length = expression_string.length();
        int previous_operator_position = -1;
        int multiplication_position;
        int next_operator_position = expression_length;
        bool multiplication_found = false;

        for(int i=0; i < expression_length; i++) {
            c = expression_string.at(i);
            if ((c == '-' || c == '+' ) && !multiplication_found) {
                previous_operator_position = i;
            }
            else if ((c == '*') && !multiplication_found){
                multiplication_found = true;
                multiplication_position = i;
            }
            else if ((c == '*' || c == '-' || c == '+' ) && multiplication_found){
                next_operator_position = i;
                break;
            }
            else if ((i == expression_length - 1) && !multiplication_found){
                all_multiplication_complete = true;
            }
        }
        if (multiplication_found && !all_multiplication_complete){
            string first_number_string;
            string second_number_string;
            for(int i = previous_operator_position + 1; i < multiplication_position; i++){
                first_number_string += expression_string.at(i);
            }
            for(int i = multiplication_position + 1; i < next_operator_position; i++){
                second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) * stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }
    }

    while (!all_addition_complete){
        int expression_length = expression_string.length();
        int previous_operator_position = -1;
        int addition_position;
        int next_operator_position = expression_length;
        bool addition_found = false;

        for(int i=0; i < expression_length; i++) {
            c = expression_string.at(i);
            if ((c == '-') && !addition_found) {
                previous_operator_position = i;
            }
            else if ((c == '+') && !addition_found){
                addition_found = true;
                addition_position = i;
            }
            else if ((c == '-' || c == '+' ) && addition_found){
                next_operator_position = i;
                break;
            }
            else if ((i == expression_length - 1) && !addition_found){
                all_addition_complete = true;
            }
        }
        if (addition_found && !all_addition_complete){
            string first_number_string;
            string second_number_string;
            for(int i = previous_operator_position + 1; i < addition_position; i++){
                first_number_string += expression_string.at(i);
            }
            for(int i = addition_position + 1; i < next_operator_position; i++){
                second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) + stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }
    }

    while (!all_subtraction_complete){
        int expression_length = expression_string.length();
        int previous_operator_position = -1;
        int subtraction_position;
        int next_operator_position = expression_length;
        bool subtraction_found = false;

        for(int i=0; i < expression_length; i++) {
            c = expression_string.at(i);
            if ((c == '-') && !subtraction_found){
                subtraction_found = true;
                subtraction_position = i;
            }
            else if ((c == '-') && subtraction_found){
                next_operator_position = i;
                break;
            }
            else if ((i == expression_length - 1) && !subtraction_found){
                all_subtraction_complete = true;
            }
        }
        if (subtraction_found && !all_subtraction_complete){
            string first_number_string;
            string second_number_string;
            for(int i = previous_operator_position + 1; i < subtraction_position; i++){
                first_number_string += expression_string.at(i);
            }
            for(int i = subtraction_position + 1; i < next_operator_position; i++){
                second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) - stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }
    }
    ui->txtAns->setText(QString::fromStdString(expression_string));
}

