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
    // Constructor
    explicit MainWindow(QWidget *parent = nullptr);

    // Destructor
    ~MainWindow();

private slots:

    // Slots for digit buttons (0–9)
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    // Slots for operation buttons
    void on_pushButton_add_clicked();      // +
    void on_pushButton_minus_clicked();    // -
    void on_pushButton_multiply_clicked(); // *
    void on_pushButton_divide_clicked();   // /

    // Slot for clearing all data
    void on_pushButton_clear_clicked();

    // Slot for calculating the result
    void on_pushButton_Enter_clicked();

private:

    // Pointer to UI elements
    Ui::MainWindow *ui;

    // Stores first number as string
    QString number1 = "";

    // Stores second number as string
    QString number2 = "";

    // Input state:
    // 1 = user is entering first number
    // 2 = user is entering second number
    int state = 1;

    // Selected operation:
    // 0 = addition (+)
    // 1 = subtraction (-)
    // 2 = multiplication (*)
    // 3 = division (/)
    int operand = -1;

    // Handles digit button clicks
    void numberClickHandler(int digit);

    // Clears all variables and input fields
    void clearAll();
};

#endif // MAINWINDOW_H
