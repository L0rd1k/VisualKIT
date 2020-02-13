/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreadableObject.h
 * Author: Ilya Petrikov
 *
 * Created on December 27, 2019, 4:43 PM
 */

#ifndef THREADABLEOBJECT_H
#define THREADABLEOBJECT_H

#include <QObject>
#include <QThread>
#include <QCoreApplication>
#include <QDebug>
#include <QMutex>

class ThreadableObject : public QObject {
    Q_OBJECT
protected:
    QThread* thread = nullptr;
    bool isDestroyed;
public:
    ThreadableObject();
    virtual ~ThreadableObject();
public slots:
    void ConnectWithThread(QThread* _thread);
    void Destroy();
    virtual void Init();
    virtual void OnDestroy();
    QThread* GetThread();
signals:
    void Destroying();
    void Destroyed();
};

#endif /* THREADABLEOBJECT_H */

