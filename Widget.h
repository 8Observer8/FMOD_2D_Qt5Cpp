#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <fmod.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    FMOD_SYSTEM *m_pSystem;
    FMOD_SOUND *m_pSound;
};
#endif // WIDGET_H
