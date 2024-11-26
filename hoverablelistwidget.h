#ifndef HOVERABLELISTWIDGET_H
#define HOVERABLELISTWIDGET_H

#include <QListWidget>
#include <QMouseEvent>

class HoverableListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit HoverableListWidget(QWidget *parent = nullptr);

signals:
    void itemHovered(QListWidgetItem *item); // 悬浮信号

protected:
    void mouseMoveEvent(QMouseEvent *event) override; // 重写鼠标移动事件
};

#endif // HOVERABLELISTWIDGET_H
