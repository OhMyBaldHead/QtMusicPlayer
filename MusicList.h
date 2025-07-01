#ifndef MUSICLIST_H
#define MUSICLIST_H
#include<vector>
using namespace std; 

#include"Music.h"
#include <QListWidget>

enum PlaybackMode {
    LoopAll,      // 列表循环
    LoopOne,      // 单曲循环
    Random        // 随机播放
};

class MusicListWidget;
//歌曲列表
class MusicList
{
public:
    //歌单名
    QString name;
    //所存储的歌曲
    vector<Music> music;
    //循环方式
    PlaybackMode playMode = PlaybackMode::LoopAll;

    friend class MainWidget;

public:
    MusicList(){}
    MusicList(const QList<QUrl>& urls,QString iname="");
    //设定歌单名
    void setName(const QString& iname){name=iname;}
    QString getName(){ return name; }
    //从url添加歌曲
    void addMusic(const QList<QUrl>& urls);
    //添加一首歌曲
    void addMusic(const Music& iMusic);
    //获取指定位置的歌曲
    Music getMusic(int pos);
    //歌单可视化
    void addToListWidget(MusicListWidget *listWidget);
    //移除指定的歌曲
    void removeMusic(int pos);
    //显示指定歌曲详细信息
    void detail(int pos);
    //清空本歌单
    void clear();
    //设置列表循环方式
    void setPlayBackMode(PlaybackMode mode);
};

#endif // MUSICLIST_H
