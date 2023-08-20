#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include "global.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUI();

    // 初始化
    thread = nullptr;
    index = -1;
    isCirculate = 0;

    // 初始化路径
    nameFile = "";
    picPath = "";

    // 设定初始帧率
    v = 10;
    frameLabel->setText(QString::number(v));

    // 设定为未工作状态
    isWorking = false;
}

MainWindow::~MainWindow()
{
    delete ui;

    // 安全删除线程
    if(thread != nullptr)
        thread->deleteLater();
}

// 准备工作
void MainWindow::on_pushButton_select_clicked()
{
    nameFile=QFileDialog::getOpenFileName(this,QString("选择文件"),QString("../.."),"nameFile (*.txt);;");
    nameFileLabel->setText(nameFile);
    qDebug() << nameFile;

    // 处理文件
    QFile tempFile;     // 打开的文件
    tempFile.setFileName(nameFile);
    if(tempFile.open(QIODevice::ReadOnly)) {
        // 读取并按行分割记录
        QString strAll = tempFile.readAll();
        picPathList = strAll.split("\r\n");
        if(picPathList.at(picPathList.size()-1).isEmpty())
            picPathList.removeAt(picPathList.size()-1); // 处理末尾回车
    }
    else
        qDebug()<<"nameFile ERROR!";
    tempFile.close();
}
void MainWindow::on_pushButton_folder_clicked()
{
    picPath = QFileDialog::getExistingDirectory(this);
    picPathLabel->setText(picPath);
    qDebug() << picPath;

    // 补充picPathList前缀
    for(int i=0; i < picPathList.size(); i++) {
        picPathList.replace(i, picPath+"/"+picPathList.at(i));
        qDebug() << picPathList.at(i);
    }

    // 进入缓存
    images = new QImage[picPathList.size()];
    for(int i=0; i < picPathList.size(); i++)
        if(!images[i].load(picPathList.at(i)))
            qDebug()<< picPathList.at(i) << " fail!!!!!!!!!!!!!!";
}


void MainWindow::on_pushButton_start_clicked()
{
    if(thread == nullptr && !isWorking) {
        // 准备工作
        index = -1;
        isCirculate = 1;
        handle = 1;

        thread = new MyThread(this);
        connect(thread, &MyThread::refresh, this, &MainWindow::switchPic);
        thread->start();

        isWorking = true;
        qDebug() << "start";
    }
}

void MainWindow::on_pushButton_stop_clicked()
{
    if(isWorking) {
        // 安全删除线程
        handle = 0;
        thread->exit();
        thread->deleteLater();
        thread = nullptr;

        // 初始化
        index = -1;
        isCirculate = 0;

        isWorking = false;
        qDebug() << "stop";
    }
}

void MainWindow::switchPic()
{
    // 处理下标
    index = (index+1)%picPathList.size();
    ui->label->setPixmap(QPixmap::fromImage(images[index]));
}



void MainWindow::setUI()
{
    this->setWindowTitle("Fluent") ;
    this->setWindowIcon(QIcon("://images/02.jpg")) ;
    this->setStyleSheet("background-color:rgb(208, 236, 255);");


    // 状态栏____________________________________________________________
    label = new QLabel(this);
    label->setText("帧率");
    label->setFont(QFont("Consolas",8,75)) ;
    label->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->statusbar->addWidget(label);

    frameLabel = new QLineEdit(this);
    frameLabel->setFont(QFont("Consolas",8,75)) ;
    label->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->statusbar->addWidget(frameLabel);

    nameFileLabel = new QLabel(this);
    nameFileLabel->setFont(QFont("Consolas",8,75)) ;
    nameFileLabel->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->statusbar->addWidget(nameFileLabel);

    picPathLabel = new QLabel(this);
    picPathLabel->setFont(QFont("Consolas",8,75)) ;
    picPathLabel->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->statusbar->addWidget(picPathLabel);

    picLabel = new QLabel(this);
    picLabel->setFont(QFont("Consolas",8,75)) ;
    picLabel->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->statusbar->addWidget(picLabel);

    // 帧率可修改
    connect(frameLabel,&QLineEdit::returnPressed,[=]() {
        v = frameLabel->text().toInt();
        frameLabel->setText(QString::number(v));
        qDebug() << "v =" << v;
    });



    // 优化
    ui->label->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_select->setFont(QFont("Consolas",10,75)) ;
    ui->pushButton_select->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_folder->setFont(QFont("Consolas",10,75)) ;
    ui->pushButton_folder->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_start->setFont(QFont("Consolas",10,75)) ;
    ui->pushButton_start->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_stop->setFont(QFont("Consolas",10,75)) ;
    ui->pushButton_stop->setStyleSheet("background: rgba(255,255,255,50%)") ;
}
