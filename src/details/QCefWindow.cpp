﻿#include "QCefWindow.h"

#include <QDebug>

QCefWindow::QCefWindow()
  : QWindow()
{
  setFlag(Qt::FramelessWindowHint);
}

QCefWindow::~QCefWindow()
{
  qDebug() << this << "is being destructed";
}

void
QCefWindow::attachCefWindow(QWindow* win)
{
  detachCefWindow();
  cefWindow_ = win;
  cefWindow_->setParent(this);
}

void
QCefWindow::detachCefWindow()
{
  if (cefWindow_) {
    cefWindow_->hide();
    cefWindow_->setParent(nullptr);
    cefWindow_ = nullptr;
  }
}

QWindow*
QCefWindow::cefWindow()
{
  return cefWindow_;
}

void
QCefWindow::resizeEvent(QResizeEvent* e)
{
  if (cefWindow_) {
    cefWindow_->resize(e->size());
  }
  QWindow::resizeEvent(e);
}
