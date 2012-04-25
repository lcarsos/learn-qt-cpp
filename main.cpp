#include <QApplication>
#include <QTextEdit>

int main(int argv, char **args) {
	QApplication app(argv, args);

	QTextEdit textEdit;
	textEdit.show();

	return app.exec();
}

/* vim: set noet sw=4 ts=4 ai: */
