//
// Created by dingjing on 5/12/22.
//

#ifndef MAILSPRING_ACTIONLABEL_H
#define MAILSPRING_ACTIONLABEL_H
#include <QToolButton>

class ActionLabel : public QToolButton
{
    Q_OBJECT
public:
    explicit ActionLabel (QWidget *parent = nullptr);
    explicit ActionLabel (QAction *action, QWidget *parent = nullptr);

    ~ActionLabel () override;

    QSize sizeHint () const override;
    QSize minimumSizeHint () const override;

protected:
    void init ();

};


#endif //MAILSPRING_ACTIONLABEL_H
