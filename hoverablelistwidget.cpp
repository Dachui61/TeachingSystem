#include "HoverableListWidget.h"

HoverableListWidget::HoverableListWidget(QWidget *parent)
    : QListWidget(parent)
{
    setMouseTracking(true); // 启用鼠标追踪

    // 设置样式表，调整字体大小
    setStyleSheet(R"(
        QListWidget::item {
            font-size: 25px; /* 设置字体大小 */
            padding: 5px;   /* 添加内边距，使项之间更清晰 */
        }
        QListWidget::item:hover {
            background-color: #f0f0f0; /* 鼠标悬浮时的背景色 */
        }
    )");
}

void HoverableListWidget::mouseMoveEvent(QMouseEvent *event)
{
    // 获取当前鼠标悬浮的项
    QListWidgetItem *hoveredItem = itemAt(event->pos());

    // 发射悬浮信号
    emit itemHovered(hoveredItem);

    // 调用父类的鼠标移动事件
    QListWidget::mouseMoveEvent(event);
}
