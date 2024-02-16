#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include "stack"
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

QString display_expression;

void MainWindow::on_zeroButton_clicked()
{
    display_expression.append("0");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_oneButton_clicked()
{
    display_expression.append("1");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_twoButton_clicked()
{
    display_expression.append("2");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_threeButton_clicked()
{
    display_expression.append("3");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_fourButton_clicked()
{
    display_expression.append("4");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_fiveButton_clicked()
{
    display_expression.append("5");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_sixButton_clicked()
{
    display_expression.append("6");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_sevenButton_clicked()
{
    display_expression.append("7");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_eightButton_clicked()
{
    display_expression.append("8");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_nineButton_clicked()
{
    display_expression.append("9");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_pointButton_clicked()
{
    display_expression.append(".");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_additionButton_clicked()
{
    display_expression.append("+");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_subtractionButton_clicked()
{
    display_expression.append("-");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_multiplicationButton_clicked()
{
    display_expression.append("*");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_divisionButton_clicked()
{
    display_expression.append("/");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_leftBracketButton_clicked()
{
    display_expression.append("(");
    ui->txtExpression->setText(display_expression);
}


void MainWindow::on_rightBracketButton_clicked()
{
    display_expression.append(")");
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_deleteButton_clicked()
{
    display_expression.removeLast();
    ui->txtExpression->setText(display_expression);
}

void MainWindow::on_clearButton_clicked()
{
    display_expression.clear();
    ui->txtExpression->setText(display_expression);
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority(char c)  {
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

double calculate(double a, double b, char c) {
    if (c == '/')
        return a / b;
    else if (c == '*')
        return a * b;
    else if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else return 0; // error needed here
}

QString shuntingYard(const QString& display_expression)
{
    string expression_string = display_expression.toStdString();
    stack<double> values;
    stack<char> operators;
    size_t expression_length = expression_string.length();
    int unclosed_brackets = 0;
    for (size_t i = 0; i < expression_length; i++) {
        if (isspace(expression_string[i])) {
            continue;
        }
        if (((unclosed_brackets == 1 && expression_string[i] != ')' ) || (unclosed_brackets > 1)) && i == expression_length - 1) {
            return "missmatched brackets error!";
        }
        if (isdigit(expression_string[i]) || ((expression_string[i] == '-' || expression_string[i] == '+') && (i == 0 || !(isdigit(expression_string[i-1]) || expression_string[i-1] == ')')))) {
            string num;
            if ((expression_string[i] == '-' || expression_string[i] == '+') && !isdigit(expression_string[i+1]))
                return "too many operators in a row error!";
            if (expression_string[i] == '-') {
                num += '-';
                i++;
            }
            if (expression_string[i] == '+') {
                i++;
            }
            while (i < expression_length && (isdigit(expression_string[i]) || expression_string[i] == '.')) {
                num += expression_string[i];
                i++;
            }
            --i;
            values.push(stod(num));
        }
        else if (expression_string[i] == '(') {
            operators.push(expression_string[i]);
            ++unclosed_brackets;
        }
        else if (expression_string[i] == ')' && unclosed_brackets>0) {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char c = operators.top();
                operators.pop();
                values.push(calculate(a, b, c));
            }
            operators.pop();
            --unclosed_brackets;
        }
        else if (isOperator(expression_string[i]) && !((expression_string[i] == '*' || expression_string[i] == '/') && isOperator(expression_string[i-1])) && i != 0 && i != expression_length - 1) {
            while (!operators.empty() && priority(operators.top()) >= priority(expression_string[i])) {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char c = operators.top();
                operators.pop();
                values.push(calculate(a, b, c));
            }
            operators.push(expression_string[i]);
        }
        else return "error!";
    }
    while (!operators.empty()) {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char c = operators.top();
        operators.pop();
        values.push(calculate(a, b, c));
    }
    if (unclosed_brackets > 0)
        return "missmatched brackets error!";
    return QString::number(values.top());
}



QString oldMethod(QString display_expression)
{
    if (display_expression.isEmpty()){
        return "";
    }
    string expression_string = display_expression.toStdString();
    QString expression_QString;
    char c;
    bool all_mult_and_div_complete = false;
    bool all_add_and_sub_complete = false;

    while (!all_mult_and_div_complete){
        int expression_length = expression_string.length();
        int previous_operator_position = -1;
        int div_or_mult_position = -1;
        int next_operator_position = expression_length;
        bool div_found = false;
        bool mult_found = false;

        for(int i=0; i < expression_length; i++) {
            c = expression_string.at(i);
            if ((c == '-' || c == '+') && !div_found && !mult_found) {
                if ((i == previous_operator_position + 1) && c =='-') {
                    expression_string[i] = 'm';
                }
                else if ((i == previous_operator_position + 1) && c =='+') {
                    expression_string[i] = ' ';
                }
                else if (i == expression_length-1) {
                    expression_QString = QString("Invalid Operator Position: %1").arg(c);
                    return expression_QString;
                }
                else {
                    previous_operator_position = i;
                }
            }
            else if (c == '/' && !div_found && !mult_found){
                if (i == 0 || i == expression_length-1) {
                    expression_QString = QString("Invalid Operator Position: %1").arg(c);
                    return expression_QString;
                }
                div_found = true;
                div_or_mult_position = i;
            }
            else if (c == '*' && !div_found && !mult_found){
                if (i == 0 || i == expression_length-1) {
                    expression_QString = QString("Invalid Operator Position: %1").arg(c);
                    return expression_QString;
                }
                mult_found = true;
                div_or_mult_position = i;
            }
            else if ((c == '/' || c == '*' || c == '-' || c == '+' ) && (div_found || mult_found)){
                if ((i == div_or_mult_position + 1) && c =='-') {
                    expression_string[i] = 'm';
                }
                else if ((i == div_or_mult_position + 1) && c =='+') {
                    expression_string[i] = ' ';
                }
                else if (i == expression_length-1) {
                    expression_QString = QString("Invalid Operator Position: %1").arg(c);
                    return expression_QString;
                }
                else {
                    next_operator_position = i;
                    break;
                }
            }
            else if ((i == expression_length - 1) && !div_found && !mult_found){
                all_mult_and_div_complete = true;
            }
        }
        if (div_found && !all_mult_and_div_complete){
            string first_number_string;
            string second_number_string;
            if (div_or_mult_position - previous_operator_position == 1 || next_operator_position - div_or_mult_position == 1) {
                expression_string = "Error: Two or more consecutive operators!";
                return QString::fromStdString(expression_string);
            }
            for(int i = previous_operator_position + 1; i < div_or_mult_position; i++){
                if (expression_string.at(i) == 'm')
                    first_number_string += '-';
                else
                    first_number_string += expression_string.at(i);
            }
            for(int i = div_or_mult_position + 1; i < next_operator_position; i++){
                if (expression_string.at(i) == 'm')
                    second_number_string += '-';
                else
                    second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) / stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            if (result.at(0) == '-')
                result.at(0) = 'm';
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }
        else if (mult_found && !all_mult_and_div_complete){
            string first_number_string;
            string second_number_string;
            if (div_or_mult_position - previous_operator_position == 1 || next_operator_position - div_or_mult_position == 1) {
                expression_string = "Error: Two or more consecutive operators!";
                return QString::fromStdString(expression_string);
            }
            for(int i = previous_operator_position + 1; i < div_or_mult_position; i++){
                if (expression_string.at(i) == 'm')
                    first_number_string += '-';
                else
                    first_number_string += expression_string.at(i);
            }
            for(int i = div_or_mult_position + 1; i < next_operator_position; i++){
                if (expression_string.at(i) == 'm')
                    second_number_string += '-';
                else
                    second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) * stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            if (result.at(0) == '-')
                result.at(0) = 'm';
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
                expression_string = "Error: Two or more consecutive operators!";
                return QString::fromStdString(expression_string);
            }
            for(int i = previous_operator_position + 1; i < add_or_sub_position; i++){
                if (expression_string.at(i) == 'm')
                    first_number_string += '-';
                else
                    first_number_string += expression_string.at(i);
            }
            for(int i = add_or_sub_position + 1; i < next_operator_position; i++){
                if (expression_string.at(i) == 'm')
                    second_number_string += '-';
                else
                    second_number_string += expression_string.at(i);
            }

            string result = to_string(stod(first_number_string) + stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            if (result.at(0) == '-')
                result.at(0) = 'm';
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }

        else if (sub_found && !all_add_and_sub_complete){
            string first_number_string;
            string second_number_string;
            if (add_or_sub_position - previous_operator_position == 1 || next_operator_position - add_or_sub_position == 1) {
                expression_string = "Error: Two or more consecutive operators!";
                return QString::fromStdString(expression_string);
            }
            for(int i = previous_operator_position + 1; i < add_or_sub_position; i++){
                if (expression_string.at(i) == 'm')
                    first_number_string += '-';
                else
                    first_number_string += expression_string.at(i);
            }
            for(int i = add_or_sub_position + 1; i < next_operator_position; i++){
                if (expression_string.at(i) == 'm')
                    second_number_string += '-';
                else
                    second_number_string += expression_string.at(i);
            }
            string result = to_string(stod(first_number_string) - stod(second_number_string));
            result.erase ( result.find_last_not_of('0') + 1, string::npos );
            result.erase ( result.find_last_not_of('.') + 1, string::npos );
            if (result.at(0) == '-')
                result.at(0) = 'm';
            expression_string.erase(previous_operator_position + 1, next_operator_position-previous_operator_position - 1);
            expression_string.insert(previous_operator_position + 1, result);
        }
    }
    if (expression_string.at(0) == 'm')
        expression_string.at(0) = '-';
    return QString::fromStdString(expression_string);
}


void MainWindow::on_equalsButton_clicked()
{
    ui->txtAns->setText(shuntingYard(display_expression));
    //ui->txtAns->setText(oldMethod(display_expression));
}


void MainWindow::on_txtExpression_textChanged(const QString &text)
{
    display_expression = text;
}


void MainWindow::on_txtExpression_returnPressed()
{
    MainWindow::on_equalsButton_clicked();
}

