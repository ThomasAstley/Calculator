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

    const QList<QPushButton *> buttons = {
        ui->zeroButton, ui->oneButton, ui->twoButton, ui->threeButton, ui->fourButton,
        ui->fiveButton, ui->sixButton, ui->sevenButton, ui->eightButton, ui->nineButton,
        ui->pointButton, ui->additionButton, ui->subtractionButton, ui->multiplicationButton,
        ui->divisionButton, ui->leftBracketButton, ui->rightBracketButton, ui->ansButton, ui->scientificNotationButton
    };
    for (QPushButton *button : buttons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::onNumberOrSymbolButtonClicked);
    }
    ui->txtExpression->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString display_expression;

QString previous_answer;

void MainWindow::onNumberOrSymbolButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button)
        return;
    QString buttonText = button->text();
    int cursorPosition = ui->txtExpression->cursorPosition();
    display_expression.insert(cursorPosition, buttonText);
    ui->txtExpression->setText(display_expression);
    ui->txtExpression->setCursorPosition(cursorPosition + buttonText.length());
    ui->txtExpression->setFocus();
}

void MainWindow::on_deleteButton_clicked()
{
    int cursorPosition = ui->txtExpression->cursorPosition();
    display_expression.removeAt(cursorPosition-1);
    ui->txtExpression->setText(display_expression);
    ui->txtExpression->setCursorPosition(cursorPosition-1);
    ui->txtExpression->setFocus();
}

void MainWindow::on_clearButton_clicked()
{
    display_expression.clear();
    ui->txtExpression->setText(display_expression);
    ui->txtExpression->setFocus();
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

long double calculate(long double a, long double b, char c) {
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

QString shuntingYard(const QString& display_expression, const QString& previous_answer)
{
    string expression_string = display_expression.toStdString();

    if (expression_string.empty()){
        return "";
    }
    if (isOperator(expression_string.back())) {
        return "Error! Operator at end of expression";
    }
    stack<long double> values;
    stack<char> operators;
    size_t expression_length = expression_string.length();
    int unclosed_brackets = 0;
    bool negative_brackets = false;
    for (size_t i = 0; i < expression_length; i++) {
        if (isspace(expression_string[i])) {
            continue;
        }
        if (((unclosed_brackets == 1 && expression_string[i] != ')' ) || (unclosed_brackets > 1)) && i == expression_length - 1) {
            return "Error! Missmatched brackets";
        }
        if (isdigit(expression_string[i]) || ((expression_string[i] == '-' || expression_string[i] == '+') && (i == 0 || !(isdigit(expression_string[i-1]) || expression_string[i-1] == ')')))) {
            string num;
            if ((expression_string[i] == '-' || expression_string[i] == '+') && isOperator(expression_string[i+1]))
                return "Error! Too many operators in a row";
            if (expression_string[i+1] == '(') {
                if (isdigit(expression_string[i])) {
                    operators.push('*');
                }
                else if (expression_string[i] == '-'){
                    negative_brackets = true;
                    i++;
                }
                else if (expression_string[i] == '+'){
                    i++;
                }
            }
            else if (expression_string[i] == '-') {
                num += '-';
                i++;
            }
            else if (expression_string[i] == '+') {
                i++;
            }

            while (i < expression_length && (isdigit(expression_string[i]) || expression_string[i] == '.' || expression_string[i] == 'E' )) {
                if (expression_string[i] == 'E' && (expression_string[i+1] == '+' || expression_string[i+1] == '-')) {
                    num += expression_string[i];
                    num += expression_string[i+1];
                    i++;
                }
                else {
                    num += expression_string[i];
                }
                i++;
            }
            --i;
            if (!num.empty()) {
                values.push(stod(num));
            }
        }
        else if (expression_string[i] == '(') {
            if (i>0 && expression_string[i-1] == ')') {
                operators.push('*');
            }
            operators.push(expression_string[i]);
            ++unclosed_brackets;
        }
        else if (expression_string[i] == ')' && unclosed_brackets>0) {
            if (operators.top() == '(' && negative_brackets) {
                long double a = -values.top();
                values.pop();
                values.push(a);
            }
            while (!operators.empty() && operators.top() != '(') {
                long double b = values.top();
                values.pop();
                long double a = values.top();
                values.pop();
                char c = operators.top();
                operators.pop();
                if (negative_brackets) {
                    values.push(-calculate(a, b, c));
                }
                else {
                values.push(calculate(a, b, c));
                }
            }
            operators.pop();
            --unclosed_brackets;
            negative_brackets = false;
        }
        else if (isOperator(expression_string[i]) && !((expression_string[i] == '*' || expression_string[i] == '/') && isOperator(expression_string[i-1])) && i != 0 && i != expression_length - 1) {
            while (!operators.empty() && priority(operators.top()) >= priority(expression_string[i])) {
                long double b = values.top();
                values.pop();
                long double a = values.top();
                values.pop();
                char c = operators.top();
                operators.pop();
                values.push(calculate(a, b, c));
            }
            operators.push(expression_string[i]);
        }
        else if (expression_string[i] == 'A') {
            int previous_i = static_cast<int>(i);
            if (expression_string[i+1] == 'n' && expression_string[i+2] == 's') {
                string previous_answer_string = previous_answer.toStdString();
                if (!(isOperator(expression_string[i+3]) || expression_string[i+3] == ')') && i != expression_length - 3) {
                    expression_string.insert(i+3,"*");
                }
                if (!(isOperator(expression_string[i-1]) || expression_string[i-1] == '(') && i != 0 ) {
                    expression_string.insert(i,"*");
                    ++i;
                }
                if (!previous_answer_string.empty()) {
                    expression_string.replace(i, 3, previous_answer_string);
                }
                else {
                    expression_string.replace(i, 3, "0");
                }
            }
            else {
                return "Error, \"A\" not followed by \"ns\"";
            }
            expression_length = expression_string.length();
            i = previous_i - 1;
        }
        else return "error!";
    }
    while (!operators.empty()) {
        long double b = values.top();
        values.pop();
        long double a = values.top();
        values.pop();
        char c = operators.top();
        operators.pop();
        values.push(calculate(a, b, c));
    }
    if (unclosed_brackets > 0)
        return "Error! Missmatched brackets";
    return QString::number(values.top(), 'G', 15);
}


void MainWindow::on_equalsButton_clicked()
{
    previous_answer = ui->txtAns->text();
    ui->txtAns->setText(shuntingYard(display_expression, previous_answer));
    ui->txtExpression->setFocus();
}


void MainWindow::on_txtExpression_textChanged(const QString &text)
{
    display_expression = text;
}


void MainWindow::on_txtExpression_returnPressed()
{
    on_equalsButton_clicked();
}

void MainWindow::on_leftButton_clicked()
{
    int cursorPosition = ui->txtExpression->cursorPosition();
    ui->txtExpression->setCursorPosition(cursorPosition-1);
    ui->txtExpression->setFocus();
}


void MainWindow::on_rightButton_clicked()
{
    int cursorPosition = ui->txtExpression->cursorPosition();
    ui->txtExpression->setCursorPosition(cursorPosition+1);
    ui->txtExpression->setFocus();
}
