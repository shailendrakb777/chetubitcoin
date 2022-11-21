// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2019 The H2hcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef H2HCOIN_UTIL_VALIDATION_H
#define H2HCOIN_UTIL_VALIDATION_H

#include <string>

class CValidationState;

/** Convert CValidationState to a human-readable message for logging */
std::string FormatStateMessage(const CValidationState &state);

extern const std::string strMessageMagic;

#endif // H2HCOIN_UTIL_VALIDATION_H
