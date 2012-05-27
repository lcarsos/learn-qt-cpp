#include <QApplication>
#include <QFont>
#include <QPushButton>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	QPushButton quit("Quit");
	quit.resize(75,350);
	quit.setFont(QFont("Times", 18, QFont::Bold));

	QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

	quit.show();
	return app.exec();
}
