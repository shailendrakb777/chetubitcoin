// Copyright (c) 2011-2014 The H2hcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef H2HCOIN_QT_COINCONTROLTREEWIDGET_H
#define H2HCOIN_QT_COINCONTROLTREEWIDGET_H

#include <QKeyEvent>
#include <QTreeWidget>

class CoinControlTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit CoinControlTreeWidget(QWidget *parent = nullptr);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // H2HCOIN_QT_COINCONTROLTREEWIDGET_H
