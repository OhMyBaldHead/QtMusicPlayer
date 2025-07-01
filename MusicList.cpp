#include "MusicList.h"
#include <QCoreApplication>
#include <QProgressDialog>
#include <QDesktopServices>
#include "MusicListWidget.h"

MusicList::MusicList(const QList<QUrl> &urls, QString iname)
{
    addMusic(urls);
    setName(iname);
}

void MusicList::addMusic(const QList<QUrl> &urls)
{
    //实测这里耗时较长，所以添加一个进度显示对话框
    QProgressDialog proDialog(u8"添加进度",u8"取消",0,urls.size());
    proDialog.setMinimumSize(350,150);
    proDialog.setWindowModality(Qt::WindowModal);
    proDialog.setWindowTitle("添加中...请稍后");
    proDialog.show();
    int x=0;
    foreach (QUrl i, urls) {
        x++;
        proDialog.setValue(x);
        //过滤Url的类型
        if(!i.toLocalFile().endsWith(".mp3",Qt::CaseInsensitive)){
            continue;
        }
        //剩下的符合类型
        music.push_back(Music(i));
        if(proDialog.wasCanceled()) break;
    }
}

void MusicList::addMusic(const Music &iMusic)
{
    music.push_back(iMusic);
}

Music MusicList::getMusic(int pos)
{
    return music[pos];
}

void MusicList::addToListWidget(MusicListWidget *listWidget)
{
    foreach(const Music &i,music){
        QListWidgetItem *item = new QListWidgetItem;
        item->setIcon(listWidget->getIcon());
        item->setText(i.getInfo());
        listWidget->addItem(item);
    }
}

void MusicList::removeMusic(int pos)
{

    int i=0;
    for(auto it=music.begin();it!=music.end();){
        if(i==pos){
            it= music.erase(it);
            break;
        }
        else{
            it++;
        }
        i++;

    }
    
}

void MusicList::detail(int pos)
{
    music[pos].detail();
}


void MusicList::clear()
{
    music.clear();
}

void MusicList::setPlayBackMode(PlaybackMode mode){
    playMode = mode;
}

