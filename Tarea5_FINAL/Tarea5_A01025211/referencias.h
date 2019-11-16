#ifndef REFERENCIAS_H
#define REFERENCIAS_H

#include <QDialog>

namespace Ui {
class Referencias;
}

class Referencias : public QDialog
{
    Q_OBJECT

public:
    explicit Referencias(QWidget *parent = 0);
    ~Referencias();

private:
    Ui::Referencias *ui;
};

#endif // REFERENCIAS_H
