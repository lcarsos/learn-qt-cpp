#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

class LCDRange : public QWidget
{
public:
    LCDRange( QWidget* parent = 0 );
};

LCDRange::LCDRange( QWidget* parent ) : QWidget( parent )
{
    QLCDNumber* lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange( 0, 99 );
    slider->setValue( 0 );
    connect(slider, SIGNAL( valueChanged( int )), lcd, SLOT( display( int )));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget( lcd );
    layout->addWidget( slider );
    setLayout( layout );
}

class MyWidget : public QWidget
{
public:
    MyWidget( QWidget* parent = 0 );
};

MyWidget::MyWidget( QWidget* parent ) : QWidget(parent)
{
    QPushButton* quit = new QPushButton( tr("Quit") );
    quit->setFont( QFont("Times", 18, QFont::Bold) );
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QGridLayout* grid = new QGridLayout;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            LCDRange* lcdRange = new LCDRange;
            grid->addWidget(lcdRange, row, col);
        }
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addLayout(grid);
    setLayout(layout);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}
