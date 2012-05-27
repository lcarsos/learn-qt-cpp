#include <QtGui>
#include <QApplication>
#include <QPushButton>

int main(int argv, char **args) {
	QApplication app(argv, args);

	QPushButton hello("Hello World!");
	hello.resize(100,30);

	hello.show();
	return app.exec();
}
