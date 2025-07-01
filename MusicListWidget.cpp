#include "MusicListWidget.h"

MusicListWidget::MusicListWidget(QWidget *parent)
    :QListWidget (parent)
{
    
}

void MusicListWidget::refresh()
{
    clear();//先清空
    musicList.addToListWidget(this);
}

void MusicListWidget::setMusicList(const MusicList &music)
{
    musicList=music;
    refresh();
}

void MusicListWidget::removeMusic(int pos)
{
    //int pos=currentRow();
    //移除
    musicList.removeMusic(pos);
    //从ListWidget中移除
    QListWidgetItem *tempItem=takeItem(pos);
    removeItemWidget(tempItem);
    delete tempItem;
}

void MusicListWidget::detail()
{
    int pos=currentRow();
    musicList.detail(pos);
}

QUrl MusicListWidget::getNextMusicUrl(){
    if(musicList.music.size() == 0) return QUrl("");
    int pos=currentRow();
    if(musicList.playMode == LoopAll){
        pos++;
        if(pos == musicList.music.size()) pos = 0;
        setCurrentRow(pos);
        return musicList.music[pos].getUrl();
    }
    if(musicList.playMode == LoopOne){
        return musicList.music[pos].getUrl();
    }
    if(musicList.playMode == Random){
        int size = musicList.music.size();
        int RandomPos = QRandomGenerator::global()->bounded(size);
        setCurrentRow(RandomPos);
        return musicList.music[RandomPos].getUrl();
    }
    return QUrl("");
}

QUrl MusicListWidget::getPreMusicUrl(){
    if(musicList.music.size() == 0) return QUrl("");
    int pos=currentRow();
    if(musicList.playMode == LoopAll){
        pos--;
        if(pos < 0) pos = musicList.music.size()-1;
        setCurrentRow(pos);
        return musicList.music[pos].getUrl();
    }
    if(musicList.playMode == LoopOne){
        return musicList.music[pos].getUrl();
    }
    if(musicList.playMode == Random){
        int size = musicList.music.size();
        int RandomPos = QRandomGenerator::global()->bounded(size);
        setCurrentRow(RandomPos);
        return musicList.music[RandomPos].getUrl();
    }
    return QUrl("");
}
