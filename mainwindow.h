#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "Mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_select_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_folder_clicked();

private:
    Ui::MainWindow *ui;
    QLabel* label;
    QLineEdit* frameLabel;
    QLabel* nameFileLabel;
    QLabel* picPathLabel;
    QLabel* picLabel;
    void setUI();

    // 图片路径文件
    QString nameFile;
    QString picPath;            // 图片的路径
    QStringList picPathList;    // 处理这个文件进行读取
    QImage* images;             // 图片缓存
    int index;  // 播放图片下标
    int isCirculate;    // 是否循环播放

    // 参数计时
    bool isWorking;
    MyThread* thread;

    // 切换图片
    void switchPic();

    QLabel *picLab;     //显示图片的标签
    QPushButton *btn;
    QTimer *timer;      //定时器
    QStringList picList;//字符串列表，用于存储所有的文件名
    QPixmap picture;    //显示的图片



    void setFilePath();
};
#endif // MAINWINDOW_H
