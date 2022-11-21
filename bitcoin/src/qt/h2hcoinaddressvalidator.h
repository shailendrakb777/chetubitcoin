// Copyright (c) 2011-2014 The H2hcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef H2HCOIN_QT_H2HCOINADDRESSVALIDATOR_H
#define H2HCOIN_QT_H2HCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class H2hcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit H2hcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** H2hcoin address widget validator, checks for a valid h2hcoin address.
 */
class H2hcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit H2hcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // H2HCOIN_QT_H2HCOINADDRESSVALIDATOR_H
