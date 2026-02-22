#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Set up user interface
    ui->setupUi(this);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// -------- Digit buttons --------

void MainWindow::on_pushButton_1_clicked()
{
    numberClickHandler(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    numberClickHandler(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    numberClickHandler(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    numberClickHandler(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    numberClickHandler(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    numberClickHandler(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    numberClickHandler(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    numberClickHandler(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    numberClickHandler(9);
}

void MainWindow::on_pushButton_0_clicked()
{
    numberClickHandler(0);
}

// -------- Clear button --------

void MainWindow::on_pushButton_clear_clicked()
{
    // Clear all values and fields
    clearAll();
}

// -------- Enter / Calculate --------

void MainWindow::on_pushButton_Enter_clicked()
{
    // Convert input strings to numbers
    bool ok1 = false, ok2 = false;
    double a = number1.toDouble(&ok1);
    double b = number2.toDouble(&ok2);

    // Validate input
    if (!ok1 || !ok2 || operand == -1) {
        ui->lineEdit_result->setText("Error");
        return;
    }

    double res = 0.0;

    // Perform calculation based on selected operator
    if (operand == 0) res = a + b;
    else if (operand == 1) res = a - b;
    else if (operand == 2) res = a * b;
    else if (operand == 3) {
        if (b == 0.0) {
            ui->lineEdit_result->setText("Div0");
            return;
        }
        res = a / b;
    }

    // Display result
    ui->lineEdit_result->setText(QString::number(res));
}

// -------- Operator buttons --------

void MainWindow::on_pushButton_add_clicked()
{
    operand = 0;   // addition
    state = 2;     // switch to second number
}

void MainWindow::on_pushButton_minus_clicked()
{
    operand = 1;   // subtraction
    state = 2;
}

void MainWindow::on_pushButton_multiply_clicked()
{
    operand = 2;   // multiplication
    state = 2;
}

void MainWindow::on_pushButton_divide_clicked()
{
    operand = 3;   // division
    state = 2;
}

// -------- Helper functions --------

// Handles digit input
void MainWindow::numberClickHandler(int digit)
{
    if (state == 1) {
        // Append digit to first number
        number1 += QString::number(digit);
        ui->lineEdit_1->setText(number1);
    } else {
        // Append digit to second number
        number2 += QString::number(digit);
        ui->lineEdit_2->setText(number2);
    }
}

// Clears all data and input fields
void MainWindow::clearAll()
{
    number1 = "";
    number2 = "";
    state = 1;
    operand = -1;

    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_result->clear();
}
