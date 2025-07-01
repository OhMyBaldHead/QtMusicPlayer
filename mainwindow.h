#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QStandardPaths>
#include <QListWidgetItem>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

QString formatTime(qint64 timeMilliSeconds);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_localmusicButton_clicked();
    void on_deletemusicButton_clicked();
    void on_musiclistWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_musicSlider_valueChanged(int value);
    void updatePosition(qint64 position);
    void on_mediaStatusChanged(QMediaPlayer::MediaStatus status);
    void on_runstopButton_clicked();

    void on_preButton_clicked();

    void on_nextButton_clicked();

    void on_playmodeButton_clicked();

    void on_volumeButton_clicked();

    void on_volumeSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    //当前播放器
    QMediaPlayer* player;
    QAudioOutput* audioOutput;
};
#endif // MAINWINDOW_H
