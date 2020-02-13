/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreadableObject.cpp
 * Author: Ilya Petrikov
 * 
 * Created on December 27, 2019, 4:43 PM
 */

#include "ThreadableObject.h"

ThreadableObject::ThreadableObject() {
    thread = NULL;
    isDestroyed = false;
}

ThreadableObject::~ThreadableObject() {
    emit Destroyed();
}

void ThreadableObject::ConnectWithThread(QThread* _thread) {
    thread = _thread;
    this->moveToThread(thread);
    connect(thread, SIGNAL(started()), this, SLOT(Init()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(this, SIGNAL(Destroyed()), thread, SLOT(quit()));
    thread->start();
}

void ThreadableObject::Destroy() {
    if(isDestroyed) {
        return;
    }
    OnDestroy();
    this->deleteLater();
    isDestroyed = true;
}

void ThreadableObject::Init() {
}

void ThreadableObject::OnDestroy() {
}

QThread* ThreadableObject::GetThread() {
    return thread;
}