#ifndef PLATFORMCONFIG_H
#define PLATFORMCONFIG_H

#include <QDesktopWidget>
#include <QApplication>
#include <QList>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIcon>
#include <QFile>
#include <QTextCodec>
#include <QMessageBox>
#include <cstdio>
#include <QMutex>
#include <QPainter>

#define FIT   (100)
#define SCREEN_WIDTH                  (QApplication::desktop()->width())
#define SCREEN_HEIGHT                 (QApplication::desktop()->height())

#define SCREEN_WIDTH_FIT              (SCREEN_WIDTH-FIT)
#define SCREEN_HEIGHT_FIT             (SCREEN_HEIGHT-FIT)

#define log(...)                      printf(__VA_ARGS__);
#define Qlog(...)                     qDebug(__VA_ARGS__);


#ifdef Q_OS_WIN32
#define LOG_FILE_DIR                 ("LogFile")
#elif defined(Q_OS_UNIX) || defined(Q_OS_LINUX)
#define LOG_FILE_DIR                 ("/var/log/Director")
#else
#define LOG_FILE_DIR                 ("LogFile")
#endif

typedef void(*EventCall)(QWidget*);

static QRect ConverToGlobal(QWidget* w)
{
    QPoint topleft=w->mapToGlobal(w->pos());
    QPoint widthheight(w->geometry().width(),w->geometry().height());
    QPoint bottomright(topleft.x()+widthheight.x(),topleft.y()+widthheight.y());

    QRect rect(topleft,bottomright);
    return rect;
}

class QLoadSkin
{
public:
    static void setGlobalStyle(const QString &style)
    {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
    static void setStyle(QWidget* q,const QString &style)
    {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        q->setStyleSheet(qss.readAll());
        qss.close();
    }
};


template<typename DataObj>
class Singleton
{
private:
    Singleton<DataObj>(){  }
    ~Singleton<DataObj>(){  }
    static Singleton<DataObj>* instance;
public:
    DataObj m_data;
    static Singleton<DataObj>* getInstance();
    void release();
};
template<typename DataObj>
Singleton<DataObj>* Singleton<DataObj>::instance = NULL;

template<typename DataObj>
void Singleton<DataObj>::release()
{
    delete instance;
    instance = NULL;
}
/**
* get a instance from singleton. it can also
* use muti-thread,it use CriticalSection to
* make thread safe.
*/
template<typename DataObj>
Singleton<DataObj>* Singleton<DataObj>::getInstance()
{

    if (instance == NULL)
    {
        static QMutex mutex;
        mutex.lock();
        if (instance == NULL)
        {
            instance = new Singleton<DataObj>();
        }
        mutex.unlock();
    }

    return instance;
}



#endif // PLATFORMCONFIG_H
