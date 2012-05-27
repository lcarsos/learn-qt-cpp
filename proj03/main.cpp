#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	QWidget window;
	window.resize(200,120);

	QPushButton quit("Quit", &window);
	quit.setFont(QFont("Times", 16, QFont::Bold));
	quit.setGeometry(10, 40, 180, 40);
	QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

	window.show();
	return app.exec();
}
