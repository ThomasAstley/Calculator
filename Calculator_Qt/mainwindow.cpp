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

void MainWindow::on_additionButton_clicked()
{
    expression.append("+");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_subtractionButton_clicked()
{
    expression.append("-");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_multiplicationButton_clicked()
{
    expression.append("*");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_divisionButton_clicked()
{
    expression.append("/");
    ui->txtExpression->setText(expression);
}

void MainWindow::on_deleteButton_clicked()
{
    expression.removeLast();
    ui->txtExpression->setText(expression);
}

void MainWindow::on_pushButton_clicked()
{
    expression.clear();
    ui->txtExpression->setText(expression);
}

void MainWindow::on_equalsButton_clicked()
{
    if (expression.isEmpty()){
        return;
    }
    string expression_string = expression.toStdString();
    char c;
    bool all_mult_and_div_complete = false;
    bool all_add_and_sub_complete = false;

    while (!all_mult_and_div_complete){
        int expression_length = expression_string.length();
        int previous_operator_position = -1;
        int div_or_mult_position;
        int next_operator_position = expression_length;
        bool div_found = false;
        bool mult_found = false;

        for(int i=0; i < expression_length; i++) {
            c = expression_string.at(i);
            if ((c == '-' || c == '+') && !div_found && !mult_found) {
                if (i == 0 || i == expression_length-1) {
                    ui->txtAns->setText(QString("Invalid Operator Position: %1").arg(c));
                    return;
                }
                previous_operator_position = i;
            }
            else if (c == '/' && !div_found && !mult_found){
                if (i == 0 || i == expression_length-1) {
                    ui->txtAns->setText(QString("Invalid Operator Position: %1").arg(c));
                    return;
                }
                div_found = true;
                div_or_mult_position = i;
            }
            else if (c == '*' && !div_found && !mult_found){
                if (i == 0 || i == expression_length-1) {
                    ui->txtAns->setText(QString("Invalid Operator Position: %1").arg(c));
                    return;
                }
                mult_found = true;
                div_or_mult_position = i;
            }
            else if ((c == '/' || c == '*' || c == '-' || c == '+' ) && (div_found || mult_found)){
                if (i == expression_length-1) {
                    ui->txtAns->setText(QString("Invalid Operator Position: %1").arg(c));
                    return;
                }
                next_operator_position = i;
                break;
            }
            else if ((i == expression_length - 1) && !div_found && !mult_found){
                all_mult_and_div_complete = true;
            }
        }
        if (div_found && !all_mult_and_div_complete){
            string first_number_string;
            string second_number_string;
            if (div_or_mult_position - previous_operator_position == 1 || next_operator_position - div_or_mult_position == 1) {
                ui->txtAns->setText(QString("Error: Two or more consecutive operators!"));
                return;
            }
            for(int i = previous_operator_position + 1; i < div_or_mult_position; i++){
                first_number_string += expression_string.at(i);
            }
            for(int i = div_or_mult_position + 1; i < next_operator_position; i++){
                second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) / stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }
        else if (mult_found && !all_mult_and_div_complete){
            string first_number_string;
            string second_number_string;
            if (div_or_mult_position - previous_operator_position == 1 || next_operator_position - div_or_mult_position == 1) {
                ui->txtAns->setText(QString("Error: Two or more consecutive operators!"));
                return;
            }
            for(int i = previous_operator_position + 1; i < div_or_mult_position; i++){
                first_number_string += expression_string.at(i);
            }
            for(int i = div_or_mult_position + 1; i < next_operator_position; i++){
                second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) * stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }
    }

    while (!all_add_and_sub_complete){
        int expression_length = expression_string.length();
        int previous_operator_position = -1;
        int add_or_sub_position;
        int next_operator_position = expression_length;
        bool add_found = false;
        bool sub_found = false;

        for(int i=0; i < expression_length; i++) {
            c = expression_string.at(i);
            if ((c == '+') && !add_found && !sub_found){
                add_found = true;
                add_or_sub_position = i;
            }
            else if ((c == '-') && !sub_found && !add_found){
                sub_found = true;
                add_or_sub_position = i;
            }
            else if ((c == '-' || c == '+' ) && (add_found || sub_found)){
                next_operator_position = i;
                break;
            }
            else if ((i == expression_length - 1) && !add_found && !sub_found){
                all_add_and_sub_complete = true;
            }
        }
        if (add_found && !all_add_and_sub_complete){
            string first_number_string;
            string second_number_string;
            if (add_or_sub_position - previous_operator_position == 1 || next_operator_position - add_or_sub_position == 1) {
                ui->txtAns->setText(QString("Error: Two or more consecutive operators!"));
                return;
            }
            for(int i = previous_operator_position + 1; i < add_or_sub_position; i++){
                first_number_string += expression_string.at(i);
            }
            for(int i = add_or_sub_position + 1; i < next_operator_position; i++){
                second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) + stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }

        else if (sub_found && !all_add_and_sub_complete){
            string first_number_string;
            string second_number_string;
            if (add_or_sub_position - previous_operator_position == 1 || next_operator_position - add_or_sub_position == 1) {
                ui->txtAns->setText(QString("Error: Two or more consecutive operators!"));
                return;
            }
            for(int i = previous_operator_position + 1; i < add_or_sub_position; i++){
                first_number_string += expression_string.at(i);
            }
            for(int i = add_or_sub_position + 1; i < next_operator_position; i++){
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




