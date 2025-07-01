#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include<QListWidget>
#include<MusicList.h>
#include<QRandomGenerator>

class MusicListWidget:public QListWidget
{
    Q_OBJECT
public:
    //当前歌曲列表（存储的是歌曲信息）
    MusicList musicList;
    //当前展示列表项使用的图标
    QIcon icon=QIcon(":/image/image/music.png");
public:
    MusicListWidget(QWidget *parent = Q_NULLPTR);
    //刷新显示（当musicList有所变化时，需要调用）
    void refresh();
    //设置歌曲列表
    void setMusicList(const MusicList& music);
    //移除歌曲
    void removeMusic(int pos);
    //歌曲详情
    void detail();
    //设置/获取图标Icon
    void setIcon(QIcon iicon){ icon=iicon; }
    QIcon getIcon(){ return icon; }
    QUrl getNextMusicUrl();
    QUrl getPreMusicUrl();
    
    friend class MainWidget;
    
};

#endif // MYLISTWIDGET_H
