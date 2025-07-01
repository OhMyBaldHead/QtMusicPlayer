#ifndef MUSIC_H
#define MUSIC_H
#include <QString>
#include <QUrl>
#include <QFileInfo>
#include <QMediaMetaData>
#include <QStringConverter>

//歌曲类
class Music
{
private:
    //歌曲资源地址
    QUrl url;
    //歌手
    QString author;
    //歌曲名
    QString title;
    //时长
    qint64 duration; 
    //唱片集
    QString albumTitle;
    //比特率
    int audioBitRate;

    //根据歌曲url获得歌曲信息
    void refreshInfo();
    
public:
    Music(){}
    Music(QUrl iurl);
    
    //返回歌曲Url
    QUrl getUrl() const {return url;}
    //返回歌曲的信息
    QString getInfo() const;
    QString getInfo2() const;
    //弹窗显示歌曲信息
    void detail();
    //根据文件名来获取歌词路径
    QString getLyricFile();
    
    friend class MusicList;
};

#endif // MUSIC_H
