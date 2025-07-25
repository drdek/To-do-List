#include </home/gag/Документы/Projects github/To-do-List/src/mainwindow.h>
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Создаём центральный виджет и layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Поле ввода задачи
    taskInput = new QLineEdit(this);
    taskInput->setPlaceholderText("Новая задача...");
    layout->addWidget(taskInput);

    // Кнопка добавления
    addButton = new QPushButton("Добавить", this);
    layout->addWidget(addButton);

    // Список задач
    taskList = new QListWidget(this);
    layout->addWidget(taskList);

    // Кнопка удаления
    deleteButton = new QPushButton("Удалить", this);
    layout->addWidget(deleteButton);

    setCentralWidget(centralWidget);

    // Подключаем сигналы к слотам
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteTask);
    connect(taskList, &QListWidget::itemDoubleClicked, this, &MainWindow::toggleTask);

    // Загружаем задачи из файла
    QFile file("tasks.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            QString task = stream.readLine();
            taskList->addItem(task);
        }
        file.close();
    }
}

void MainWindow::addTask() {
    QString task = taskInput->text().trimmed();
    if (!task.isEmpty()) {
        taskList->addItem(task);
        taskInput->clear();
    }
}

void MainWindow::deleteTask() {
    if (taskList->currentRow() != -1) {
        delete taskList->takeItem(taskList->currentRow());
    }
}

void MainWindow::toggleTask() {
    QListWidgetItem *item = taskList->currentItem();
    if (item) {
        item->setCheckState(item->checkState() == Qt::Checked ? Qt::Unchecked : Qt::Checked);
        QFont font = item->font();
        font.setStrikeOut(item->checkState() == Qt::Checked);
        item->setFont(font);
    }
}

// Дополнительно: переопределяем closeEvent для сохранения задач

/*void MainWindow::close(QCloseEvent *event) {
    QFile file("tasks.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for (int i = 0; i < taskList->count(); ++i) {
            stream << taskList->item(i)->text() << "\n";
        }
        file.close();
    }
    event->accept();
} */ 