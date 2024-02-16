#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_oneButton_clicked();

    void on_zeroButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_pointButton_clicked();

    void on_additionButton_clicked();

    void on_subtractionButton_clicked();

    void on_multiplicationButton_clicked();

    void on_divisionButton_clicked();

    void on_deleteButton_clicked();

    void on_equalsButton_clicked();

    void on_clearButton_clicked();

    void on_txtExpression_textChanged(const QString &arg1);

    void on_txtExpression_returnPressed();


    void on_leftBracketButton_clicked();

    void on_rightBracketButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
