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
    void onNumberOrSymbolButtonClicked();

    void on_deleteButton_clicked();

    void on_equalsButton_clicked();

    void on_clearButton_clicked();

    void on_txtExpression_textChanged(const QString &arg1);

    void on_txtExpression_returnPressed();

    void on_leftButton_clicked();

    void on_rightButton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
