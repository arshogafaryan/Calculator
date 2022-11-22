#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
private slots:
    void digits_number();
    void operations();
    void on_pushButton_dot_clicked();
    void math_operations();
    void on_pushButton_equ_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_del_clicked();
};
#endif // CALCULATOR_H
