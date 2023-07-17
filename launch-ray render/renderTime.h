#pragma once
#include "ui_renderTime.h"
class renderTime : public QWidget
{
    Q_OBJECT

public:
    renderTime(QWidget* parent = Q_NULLPTR);
    void setRenderTime(float time);
private:
    Ui::renderTime ui;
};