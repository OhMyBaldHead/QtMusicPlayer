#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //播放器设置
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    //界面初始ui设置
    ui->musiclistWidget->musicList.setPlayBackMode(PlaybackMode::LoopAll);
    ui->playmodeButton->setIcon(QIcon(":/image/image-hover/loop-hover.png"));
    ui->runstopButton->setIcon(QIcon(":/image/image-hover/pase-hover.png"));
    QPixmap pixmap(":/image/image/non-music.png");
    ui->lblmusicpicture->setPixmap(pixmap);
    ui->volumeSlider->hide();
    ui->musiclistWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //窗口设置
    setWindowFlag(Qt::FramelessWindowHint);  // 设置无边框
    setFixedSize(width(), height());         // 设置固定窗口大小

    //设置退出按钮
    connect(ui->exitButton, &QPushButton::clicked,this, &QMainWindow::close);
    //音乐播放进度和设置显示参函数
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::updatePosition);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::on_mediaStatusChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    // 加载背景图
    QPixmap pixmap(":/image/background/background.jpg");
    if (!pixmap.isNull()) {
        // 让图片适配窗口大小，覆盖整个窗口
        painter.drawPixmap(this->rect(), pixmap.scaled(this->size(),
                                                       Qt::KeepAspectRatioByExpanding,
                                                       Qt::SmoothTransformation));
    }
    // 记得调用父类事件，保证其他绘制逻辑正常
    QMainWindow::paintEvent(event);
}

void MainWindow::on_localmusicButton_clicked()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setWindowTitle(tr("添加本地音乐（注：自动过滤，按下\"Ctrl+A\"全选添加即可；不支持添加文件夹）"));
    QStringList list;
    list<<"application/octet-stream";
    fileDialog.setMimeTypeFilters(list);
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted){
        QList<QUrl> urls=fileDialog.selectedUrls();
        ui->musiclistWidget->musicList.addMusic(urls);
        ui->musiclistWidget->refresh();
        ui->musiclistWidget->setCurrentRow(0);
    }
}

QString formatTime(qint64 timeMilliSeconds)
{
    qint64 seconds = timeMilliSeconds / 1000;
    const qint64 minutes = seconds / 60;
    seconds -= minutes * 60;
    return QStringLiteral("%1:%2")
        .arg(minutes, 2, 10, QLatin1Char('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'));
}


void MainWindow::on_deletemusicButton_clicked()
{
    //删除
    int row = ui->musiclistWidget->currentRow();
    ui->musiclistWidget->removeMusic(row);
    ui->musiclistWidget->refresh();
    //进行切歌
    QUrl nexturl = ui->musiclistWidget->getNextMusicUrl();
    player->setSource(nexturl);

}

void MainWindow::on_musiclistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int row = ui->musiclistWidget->currentRow();
    QUrl url = ui->musiclistWidget->musicList.getMusic(row).getUrl();
    player->setSource(url);
}


void MainWindow::on_musicSlider_valueChanged(int value)
{
    if (qAbs(player->position() - value) > 99)
        player->setPosition(value);
}

void MainWindow::updatePosition(qint64 position)
{
    ui->musicSlider->setValue(static_cast<int>(position));
    ui->lblmusictime->setText(formatTime(position)+"/"+formatTime(player->duration()));
    ui->musicLyricWidget->show(position);
}

void MainWindow::on_mediaStatusChanged(QMediaPlayer::MediaStatus status){
    // 输出当前状态（用于调试）
    QString statusStr;
    switch (status) {
    case QMediaPlayer::LoadingMedia: statusStr = "加载中..."; break;
    case QMediaPlayer::LoadedMedia: statusStr = "加载完成，准备播放"; break;
    case QMediaPlayer::BufferingMedia: statusStr = "缓冲中..."; break;
    case QMediaPlayer::EndOfMedia: statusStr = "播放结束"; break;
    default: statusStr = "未知状态";
    }
    //qDebug() << "媒体状态变更：" << statusStr;
    //加载音乐过程中顺便加载歌词
    if (status == QMediaPlayer::LoadingMedia){
        int pos = ui->musiclistWidget->currentRow();
        QString lyricurl = ui->musiclistWidget->musicList.getMusic(pos).getLyricFile();
        ui->musicLyricWidget->process(lyricurl);
        QPixmap pixmap(":/image/background/musicpicture.png");
        ui->lblmusicpicture->setPixmap(pixmap);
    }

    //加载音乐完毕，开始播放音乐
    if (status == QMediaPlayer::LoadedMedia) {
        //显示歌曲信息
        int pos = ui->musiclistWidget->currentRow();
        QString info2 = ui->musiclistWidget->musicList.music[pos].getInfo2();
        ui->lblmusicname->setText(info2);
        player->play();

        //设置播放键和滑动窗口
        ui->runstopButton->setIcon(QIcon(":/image/image/play.png"));
        ui->musicSlider->setRange(0, static_cast<int>(player->duration()));
        ui->musicSlider->setEnabled(static_cast<int>(player->duration()) > 0);
    }
    //播放结束后切歌
    if(status == QMediaPlayer::EndOfMedia){
        QUrl nexturl = ui->musiclistWidget->getNextMusicUrl();
        player->setSource(nexturl);
    }
}

void MainWindow::on_runstopButton_clicked()
{
    if(player->isPlaying())
    {
        player->pause();
        ui->runstopButton->setIcon(QIcon(":/image/image/pase.png"));

    }
    else if(!player->isPlaying()){
        if(player->mediaStatus() == QMediaPlayer::NoMedia){
            if(ui->musiclistWidget->musicList.music.size()>0){
                int pos = ui->musiclistWidget->currentRow();
                QUrl url = ui->musiclistWidget->musicList.getMusic(pos).getUrl();
                player->setSource(url);
            }
        }
        else{
            player->play();
            ui->runstopButton->setIcon(QIcon(":/image/image/play.png"));
        }
    }

}


void MainWindow::on_preButton_clicked()
{
    QUrl nexturl = ui->musiclistWidget->getPreMusicUrl();
    player->setSource(nexturl);
}



void MainWindow::on_nextButton_clicked()
{
    QUrl nexturl = ui->musiclistWidget->getNextMusicUrl();
    player->setSource(nexturl);
}


void MainWindow::on_playmodeButton_clicked()
{
    if(ui->musiclistWidget->musicList.playMode == PlaybackMode::LoopAll){
        ui->musiclistWidget->musicList.setPlayBackMode(PlaybackMode::LoopOne);
        ui->playmodeButton->setIcon(QIcon(":/image/image-hover/loop-one-hover.png"));
    }
    else if(ui->musiclistWidget->musicList.playMode == PlaybackMode::LoopOne){
        ui->musiclistWidget->musicList.setPlayBackMode(PlaybackMode::Random);
        ui->playmodeButton->setIcon(QIcon(":/image/image-hover/play-random-hover.png"));
    }
    else if(ui->musiclistWidget->musicList.playMode == PlaybackMode::Random){
        ui->musiclistWidget->musicList.setPlayBackMode(PlaybackMode::LoopAll);
        ui->playmodeButton->setIcon(QIcon(":/image/image-hover/loop-hover.png"));
    }
}


void MainWindow::on_volumeButton_clicked()
{
    if(ui->volumeSlider->isHidden()){
        ui->volumeSlider->show();
    }
    else{
        ui->volumeSlider->hide();
    }
}


void MainWindow::on_volumeSlider_valueChanged(int value)
{
    audioOutput->setVolume(value);
}

