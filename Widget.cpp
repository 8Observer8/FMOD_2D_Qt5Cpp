#include "Widget.h"
#include <QtCore/QFile>
#include <QtCore/QDebug>

// https://forum.qt.io/topic/49342/solved-fmod-does-not-play-a-sound-from-qresource/2

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    FMOD_System_Create(&m_pSystem, FMOD_VERSION);
    FMOD_System_Init(m_pSystem, 32, FMOD_INIT_NORMAL, 0);

//    FMOD_System_CreateSound(m_pSystem, "Assets/spell.ogg", FMOD_DEFAULT, 0, &m_pSound);

    QString soundPath(":/Assets/spell.ogg");
    QFile f(soundPath);
    if (!f.open(QIODevice::ReadOnly))
    {
        qDebug() << "Faild to open the file: " << soundPath;
        return;
    }
    QByteArray soundData = f.readAll();

    FMOD_CREATESOUNDEXINFO* exinfo = new FMOD_CREATESOUNDEXINFO();
    exinfo->length = static_cast<unsigned int>(soundData.length());
    exinfo->cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
    FMOD_System_CreateSound(m_pSystem, soundData.data(), FMOD_OPENMEMORY, exinfo, &m_pSound);

    FMOD_Sound_SetMode(m_pSound, FMOD_LOOP_OFF);

    FMOD_System_PlaySound(m_pSystem, m_pSound, 0, false, 0);
}

Widget::~Widget()
{
}
