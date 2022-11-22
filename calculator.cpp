#include "calculator.h"
#include "./ui_calculator.h"

double num_first;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_4,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_5,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_per,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_add,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_sub,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mul,SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_del->setCheckable(true);

}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::digits_number()
{
    QPushButton* button = (QPushButton*)sender();
    double numbers;
    QString new_label;
    if (ui->result_show->text().contains(".") && button->text() == '0')
    {
        new_label = ui->result_show->text() + button->text();
    }
    else
    {
        numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(numbers, 'g', 10);
    }
    ui->result_show->setText(new_label);
}


void Calculator::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}


void Calculator::operations()
{
    QPushButton* button = (QPushButton*)sender();
    double numbers;
    QString new_label;
    if (button->text() == "%")
    {
        numbers = (ui->result_show->text()).toDouble();
        numbers *= 0.01;
        new_label = QString::number(numbers, 'g', 10);

        ui->result_show->setText(new_label);
    }
}


void Calculator::math_operations()
{
    QPushButton* button = (QPushButton*)sender();
    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}


void Calculator::on_pushButton_equ_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();
    if (ui->pushButton_add->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 10);

        ui->result_show->setText(new_label);
        ui->pushButton_add->setChecked(false);
    }
    else if (ui->pushButton_sub->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 10);

        ui->result_show->setText(new_label);
        ui->pushButton_sub->setChecked(false);
    }
    else if (ui->pushButton_mul->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 10);

        ui->result_show->setText(new_label);
        ui->pushButton_mul->setChecked(false);
    }
    else if (ui->pushButton_div->isChecked())
    {
        if (num_second == 0)
            ui->result_show->setText("0");
        else
        {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 10);

            ui->result_show->setText(new_label);
        }
        ui->pushButton_div->setChecked(false);
    }

}


void Calculator::on_pushButton_C_clicked()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_sub->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_div->setChecked(false);

    ui->result_show->setText("0");
}


void Calculator::on_pushButton_del_clicked()
{
    QPushButton* button = (QPushButton*)sender();
    double numbers;
    if (button->text() == "⌫")
    {
        QString str = ui->result_show->text();
        if (str.size() == 1)
        {
            ui->result_show->setText("0");
        }
        else
        {
            str.erase(str.cend() - 1,str.cend());
            ui->result_show->setText(str);
        }
    }
}

