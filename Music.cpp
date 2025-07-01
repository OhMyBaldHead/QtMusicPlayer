#include "Music.h"
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QMessageBox>
#include <QAction>

extern QString formatTime(qint64 timeMilliSeconds);

Music::Music(QUrl iurl)
{
    url=iurl;
    refreshInfo();
}

void Music::refreshInfo(){
    QMediaPlayer *tempPlayer = new QMediaPlayer();
    tempPlayer->setSource(url);
    while(tempPlayer->metaData().isEmpty()){
        QCoreApplication::processEvents();
    }
    if (tempPlayer && !tempPlayer->metaData().isEmpty()) {
        // 获取所有可用的元数据键
        QMediaMetaData metaData = tempPlayer->metaData();
        QList<QMediaMetaData::Key> keys = metaData.keys();

        // 歌曲信息
        albumTitle = metaData.value(QMediaMetaData::AlbumTitle).toString();
        audioBitRate = metaData.value(QMediaMetaData::AudioBitRate).toInt();
        duration = tempPlayer->duration();

        QString fileName = QFileInfo(url.fileName()).fileName(); // 结果: "天路-韩红.mp3"
        // 2. 移除文件扩展名
        QString baseName = QFileInfo(fileName).completeBaseName(); // 结果: "天路-韩红"
        // 3. 使用"-"分割字符串
        QStringList parts = baseName.split("-");

        // 4. 提取歌名和歌手名
        if (parts.size() >= 2) {
            // 假设格式为 "歌名-歌手"
            title = parts[0].trimmed();      // 结果: "天路"
            author = parts[1].trimmed();     // 结果: "韩红"
        } else {
            // 格式不匹配时的默认处理
            title = baseName;                // 整个文件名作为标题
            author = "";                     // 作者为空
        }
    }
    tempPlayer->stop();
    tempPlayer->deleteLater();
    tempPlayer = nullptr;
}

QString Music::getLyricFile()
{
    QString mp3FilePath=url.toLocalFile();
    mp3FilePath.replace(".mp3",".lrc");
    mp3FilePath.replace(".flac",".lrc");
    mp3FilePath.replace(".mpga",".lrc");
    return mp3FilePath;
}

QString Music::getInfo() const
{
    return title+" - "+author+" ["+formatTime(duration)+"]";
}
QString Music::getInfo2() const
{

    return title+" - "+author;
}

void Music::detail()
{
    QString info("歌曲名：%1\n艺术家：%2\n时长：%3\n唱片集：%4\n比特率：%5\n文件路径：%6");
    info=info.arg(title,author,formatTime(duration),albumTitle,QString::number(audioBitRate)+"bps",url.toString());
    QMessageBox::about(Q_NULLPTR,"歌曲信息",info);
}


