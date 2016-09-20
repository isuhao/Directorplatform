#ifndef QCTRLWINDOW_H
#define QCTRLWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include "Model/QButton.h"
#include <QCheckBox>
#include <QSlider>
#include <QLCDNumber>
#include <QGraphicsView>


/*
 *  this widget control windows operator */



class QCtrlWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QCtrlWindow(QWidget *parent = 0);
     ~QCtrlWindow();
signals:

public slots:
private:
    QVBoxLayout *gLayout;

    /*direction Button*/
    QButton   *btn_up;
    QButton   *btn_down;
    QButton   *btn_left;
    QButton   *btn_center;
    QButton   *btn_right;

    /*switch Control use checkbox*/
    QCheckBox *meeting_ctrl;//会议控制
    QCheckBox *cloud_ctrl;//云台控制

    /*number of person*/
    QCheckBox *one_person;
    QCheckBox *two_person;
    QCheckBox *three_person;
    QCheckBox *group_person;

    QLabel  *zoom_label;
    QButton  *zoom_up; //向大变焦
    QButton  *zoom_down;//向小变焦

    QLabel   *focus_label;
    QButton  *focus_on;//放 聚焦
    QButton  *focus_off;//收 聚焦
    QCheckBox *focus_auto;

    QLabel   *ring_label;
    QButton  *ring_big;//光圈 大
    QButton  *ring_small;//光圈 小
    QCheckBox *ring_auto;

    QHBoxLayout *personlay;
    QHBoxLayout *zoomlay;
    QHBoxLayout *focuslay;
    QHBoxLayout *ringlay;

    QSlider *speed_adjust;//速度调节

    QGraphicsView *logo;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QHBoxLayout *numlay1;
    QHBoxLayout *numlay2;

    QLCDNumber *lcd_date;

    QGridLayout *dir_lay;

// some event defined
    friend void onBtn_up_up(QWidget *q);
    friend void onBtn_up_down(QWidget *q);

    friend void onBtn_down_up(QWidget *q);
    friend void onBtn_down_down(QWidget *q);

    friend void onBtn_left_up(QWidget *q);
    friend void onBtn_left_down(QWidget *q);

    friend void onBtn_right_up(QWidget *q);
    friend void onBtn_right_down(QWidget *q);


protected:
    void paintEvent(QPaintEvent* event);


};

#endif // QCTRLWINDOW_H