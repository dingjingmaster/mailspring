//
// Created by dingjing on 5/12/22.
//

#include "action-label.h"

#include <QApplication>
#include <QStyleOptionToolButton>

const char* ActionLabelStyle =
        "ActionLabel[class='action'] {"
        "background-color: transparent;"
        "border: 1px solid transparent;"
        "color: #0033ff;"
        "text-align: left;"
        "font: 11px;"
        "}"

        "ActionLabel[class='action']:!enabled {"
        "color: #999999;"
        "}"

        "ActionLabel[class='action']:hover {"
        "color: #0099ff;"
        "text-decoration: underline;"
        "}"

        "ActionLabel[class='action']:focus {"
        "border: 1px dotted black;"
        "}"

        "ActionLabel[class='action']:on {"
        "background-color: #ddeeff;"
        "color: #006600;"
        "}"
;

ActionLabel::ActionLabel (QWidget *parent) : QToolButton(parent)
{
    init ();
}

ActionLabel::ActionLabel (QAction *action, QWidget *parent) : QToolButton (parent)
{
    init ();
    setDefaultAction(action);
}

ActionLabel::~ActionLabel () = default;

QSize ActionLabel::sizeHint () const
{
    ensurePolished();

    int w = 0, h = 0;

    QStyleOptionToolButton opt;
    initStyleOption(&opt);

    QString s(text());
    bool empty = s.isEmpty();
    if (empty) {
        s = QString::fromLatin1("XXXX");
    }

    QFontMetrics fm = fontMetrics();
    QSize sz = fm.size(Qt::TextShowMnemonic, s);
    if(!empty) {
        w += sz.width();
    }
    if(!empty) {
        h = qMax(h, sz.height());
    }
    opt.rect.setSize(QSize(w, h));

    if (!icon().isNull()) {
        int ih = opt.iconSize.height();
        int iw = opt.iconSize.width() + 4;
        w += iw;
        h = qMax(h, ih);
    }

    if (menu()) {
        w += style()->pixelMetric(QStyle::PM_MenuButtonIndicator, &opt, this);
    }

    h += 4;
    w += 8;

    QSize sizeHint = (style()->sizeFromContents(QStyle::CT_PushButton, &opt, QSize(w, h), this).expandedTo(QApplication::globalStrut()));

    return sizeHint;
}

QSize ActionLabel::minimumSizeHint () const
{
    return sizeHint();;
}

void ActionLabel::init ()
{
    setProperty ("class", "action");
    setCursor (Qt::PointingHandCursor);
    setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    setStyleSheet(QString(ActionLabelStyle));

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setFocusPolicy(Qt::StrongFocus);
}
