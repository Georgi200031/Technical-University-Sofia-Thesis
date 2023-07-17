#include "renderTime.h"

renderTime::renderTime(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

void renderTime::setRenderTime(float Time) {
    ui.time->setText(QString::number(Time));
}