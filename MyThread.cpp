#include "Mythread.h"
#include <windows.h>
#include <QDebug>
#include "global.h"

MyThread::MyThread(QObject *parent)
    : QThread(parent)
{}

void MyThread::run() {
    QueryPerformanceFrequency(&cpuFreq);
    QueryPerformanceCounter(&starter);
    while(handle) {
        QueryPerformanceCounter(&ender);
        if( v*(ender.QuadPart-starter.QuadPart) >= cpuFreq.QuadPart) {
            emit refresh();
            QueryPerformanceCounter(&starter);
        }

    }
}
