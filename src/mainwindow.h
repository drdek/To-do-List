#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT  // Обязательно для сигналов/слотов!

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addTask();
    void deleteTask();
    void toggleTask();

private:
    QListWidget *taskList;
    QLineEdit *taskInput;
    QPushButton *addButton;
    QPushButton *deleteButton;
};

#endif