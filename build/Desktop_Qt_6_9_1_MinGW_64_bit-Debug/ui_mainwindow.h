/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <LyricWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "musiclistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *exitButton;
    MusicListWidget *musiclistWidget;
    LyricWidget *musicLyricWidget;
    QLabel *lblshowautor;
    QSlider *volumeSlider;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *preButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *runstopButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *playmodeButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *showlyricButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *volumeButton;
    QSlider *musicSlider;
    QLabel *lblmusictime;
    QLabel *lblmusicname;
    QLabel *lblmusicpicture;
    QPushButton *mymusiclistButton;
    QPushButton *deletemusicButton;
    QPushButton *localmusicButton;
    QPushButton *isplayingButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(976, 639);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(940, 0, 31, 31));
        exitButton->setAutoFillBackground(false);
        exitButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/quit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitButton->setIcon(icon);
        exitButton->setIconSize(QSize(18, 18));
        musiclistWidget = new MusicListWidget(centralwidget);
        musiclistWidget->setObjectName("musiclistWidget");
        musiclistWidget->setGeometry(QRect(10, 191, 201, 401));
        musiclistWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        musicLyricWidget = new LyricWidget(centralwidget);
        musicLyricWidget->setObjectName("musicLyricWidget");
        musicLyricWidget->setGeometry(QRect(190, 70, 711, 391));
        lblshowautor = new QLabel(centralwidget);
        lblshowautor->setObjectName("lblshowautor");
        lblshowautor->setGeometry(QRect(10, 10, 251, 16));
        QFont font;
        font.setPointSize(11);
        lblshowautor->setFont(font);
        lblshowautor->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(903, 474, 22, 84));
        volumeSlider->setOrientation(Qt::Orientation::Vertical);
        volumeSlider->setTickPosition(QSlider::TickPosition::NoTicks);
        volumeSlider->setTickInterval(0);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(390, 561, 541, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        preButton = new QPushButton(layoutWidget);
        preButton->setObjectName("preButton");
        preButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image-hover/pre-hover.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        preButton->setIcon(icon1);
        preButton->setIconSize(QSize(21, 21));

        horizontalLayout->addWidget(preButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        runstopButton = new QPushButton(layoutWidget);
        runstopButton->setObjectName("runstopButton");
        runstopButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image-hover/pase-hover.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        runstopButton->setIcon(icon2);
        runstopButton->setIconSize(QSize(19, 19));

        horizontalLayout->addWidget(runstopButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName("nextButton");
        nextButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image-hover/next-hover.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextButton->setIcon(icon3);
        nextButton->setIconSize(QSize(21, 21));

        horizontalLayout->addWidget(nextButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        playmodeButton = new QPushButton(layoutWidget);
        playmodeButton->setObjectName("playmodeButton");
        playmodeButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/image-hover/loop-hover.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        playmodeButton->setIcon(icon4);
        playmodeButton->setIconSize(QSize(21, 21));

        horizontalLayout->addWidget(playmodeButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        showlyricButton = new QPushButton(layoutWidget);
        showlyricButton->setObjectName("showlyricButton");
        showlyricButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/lyric.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        showlyricButton->setIcon(icon5);
        showlyricButton->setIconSize(QSize(21, 21));

        horizontalLayout->addWidget(showlyricButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        volumeButton = new QPushButton(layoutWidget);
        volumeButton->setObjectName("volumeButton");
        volumeButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/music-voice.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        volumeButton->setIcon(icon6);
        volumeButton->setIconSize(QSize(21, 21));

        horizontalLayout->addWidget(volumeButton);

        preButton->raise();
        runstopButton->raise();
        nextButton->raise();
        playmodeButton->raise();
        showlyricButton->raise();
        volumeButton->raise();
        musicSlider = new QSlider(centralwidget);
        musicSlider->setObjectName("musicSlider");
        musicSlider->setGeometry(QRect(392, 528, 371, 22));
        musicSlider->setOrientation(Qt::Orientation::Horizontal);
        lblmusictime = new QLabel(centralwidget);
        lblmusictime->setObjectName("lblmusictime");
        lblmusictime->setGeometry(QRect(770, 530, 91, 16));
        lblmusicname = new QLabel(centralwidget);
        lblmusicname->setObjectName("lblmusicname");
        lblmusicname->setGeometry(QRect(391, 503, 331, 16));
        lblmusicpicture = new QLabel(centralwidget);
        lblmusicpicture->setObjectName("lblmusicpicture");
        lblmusicpicture->setGeometry(QRect(230, 451, 141, 141));
        lblmusicpicture->setPixmap(QPixmap(QString::fromUtf8("image/background/musicpicture.png")));
        lblmusicpicture->setScaledContents(true);
        mymusiclistButton = new QPushButton(centralwidget);
        mymusiclistButton->setObjectName("mymusiclistButton");
        mymusiclistButton->setGeometry(QRect(33, 150, 111, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(12);
        font1.setBold(true);
        mymusiclistButton->setFont(font1);
        mymusiclistButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/image/myMusicList.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        mymusiclistButton->setIcon(icon7);
        mymusiclistButton->setIconSize(QSize(24, 24));
        deletemusicButton = new QPushButton(centralwidget);
        deletemusicButton->setObjectName("deletemusicButton");
        deletemusicButton->setGeometry(QRect(143, 150, 41, 41));
        deletemusicButton->setFont(font1);
        deletemusicButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/image/clear.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        deletemusicButton->setIcon(icon8);
        deletemusicButton->setIconSize(QSize(24, 24));
        localmusicButton = new QPushButton(centralwidget);
        localmusicButton->setObjectName("localmusicButton");
        localmusicButton->setGeometry(QRect(50, 100, 111, 41));
        localmusicButton->setFont(font1);
        localmusicButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/image/local-music.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        localmusicButton->setIcon(icon9);
        localmusicButton->setIconSize(QSize(24, 24));
        isplayingButton = new QPushButton(centralwidget);
        isplayingButton->setObjectName("isplayingButton");
        isplayingButton->setGeometry(QRect(50, 50, 111, 41));
        isplayingButton->setFont(font1);
        isplayingButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/image/current-music.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        isplayingButton->setIcon(icon10);
        isplayingButton->setIconSize(QSize(20, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 976, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        exitButton->setText(QString());
        lblshowautor->setText(QCoreApplication::translate("MainWindow", "QtMusicPlayer_MadeByYomo", nullptr));
        preButton->setText(QString());
        runstopButton->setText(QString());
        nextButton->setText(QString());
        playmodeButton->setText(QString());
        showlyricButton->setText(QString());
        volumeButton->setText(QString());
        lblmusictime->setText(QCoreApplication::translate("MainWindow", "00:26/05:13", nullptr));
        lblmusicname->setText(QCoreApplication::translate("MainWindow", "\350\265\267\351\243\216\344\272\206 Cover by \345\260\217\346\235\216 [05:13]", nullptr));
        lblmusicpicture->setText(QString());
        mymusiclistButton->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\346\255\214\345\215\225", nullptr));
        deletemusicButton->setText(QString());
        localmusicButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
        isplayingButton->setText(QCoreApplication::translate("MainWindow", "\346\255\243\345\234\250\346\222\255\346\224\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
