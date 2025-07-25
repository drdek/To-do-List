#include </home/gag/Документы/Projects github/To-do-List/src/mainwindow.h>
#include <QApplication>

int main (int argc, char* argv[])
{
    QApplication app(argc,argv);
   MainWindow Window;
   Window.resize(800, 600);
   Window.setWindowTitle("To-do list app");
   Window.show();

   return app.exec();

}