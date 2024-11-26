#ifndef COMPARISONDIALOG_H
#define COMPARISONDIALOG_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class ComparisonDialog;
}

class ComparisonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComparisonDialog(QWidget *parent = nullptr);
    ~ComparisonDialog();

private:
    Ui::ComparisonDialog *ui;

protected:
    void keyPressEvent(QKeyEvent *event) override;  // 添加键盘事件
};

#endif // COMPARISONDIALOG_H
